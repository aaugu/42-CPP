/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:32:10 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/21 16:32:28 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "../includes/ScalarConverter.hpp"

const char		ScalarConverter::_charMin = std::numeric_limits<char>::min();
const char		ScalarConverter::_charMax = std::numeric_limits<char>::max();
const int		ScalarConverter::_intMin = std::numeric_limits<int>::min();
const int		ScalarConverter::_intMax = std::numeric_limits<int>::max();

char	ScalarConverter::_char = '\0';
int		ScalarConverter::_int = 0;
float	ScalarConverter::_float = 0;
double	ScalarConverter::_double = 0;
bool	ScalarConverter::_charNotPrintable = false;
bool	ScalarConverter::_charOverflow = false;
bool	ScalarConverter::_intOverflow = false;
bool	ScalarConverter::_impossibleFloatDouble = false;
bool	ScalarConverter::_doubleOverflow = false;

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { *this = src; }

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) {
	(void) src;
	return (*this);
}

/* ************************************************************************** */
/*                           PUBLIC MEMBER FUNCTION                           */
/* ************************************************************************** */

void	ScalarConverter::convert(const std::string literal) {

	int type = ScalarConverter::_findType(literal);

    switch ( type ) {
		case CHAR:
			_convertLiteralToChar(literal);
			_castFromChar();
			break;
		case INT:
			_convertLiteralToInt(literal);
			_castFromInt();
			break;
		case FLOAT:
			_convertLiteralToFloat(literal);
			_castFromFloat();
			break;
		case DOUBLE:
			_convertLiteralToDouble(literal);
			_castFromDouble();
			break;
		case LITERAL:
			_charOverflow = true;
			_intOverflow = true;
			_castFromLiteral(literal);
			break;
		default:
			throw ScalarConverter::InvalidLiteral();
    }

	_printConversion();
}

/* ************************************************************************** */
/*                          PRIVATE MEMBER FUNCTION                           */
/* ************************************************************************** */

int	ScalarConverter::_findType(const std::string literal) {
	if (	literal == "inf" || literal == "+inf" || literal == "-inf"
		||  literal == "inff" || literal == "+inff" || literal == "-inff"
		||  literal == "nan" || literal == "nanf")
		return ( LITERAL );
	else
		return( StateMachine::findLiteralType(literal) );
}

// ------------------------------ Convert Literal ------------------------------
void	ScalarConverter::_convertLiteralToChar(const std::string literal) {
	_char = literal[0];
	if (!std::isprint(literal[0]))
		_charNotPrintable = true;
}

void	ScalarConverter::_convertLiteralToInt(const std::string literal) {
	char* 		endptr;
	long int	n = strtol(literal.c_str(), &endptr, 10);

	if (n < _charMin || n > _charMax)
		_charOverflow = true;
	if (n < _intMin || n > _intMax)
	{
		_intOverflow = true;
		return ;
	}

	_int = static_cast<int>(n);
}

void	ScalarConverter::_convertLiteralToFloat(const std::string literal) {
	char* 	endptr;
	_float = strtof(literal.c_str(), &endptr);

	if (_float < _charMin || _float > _charMax)
		_charOverflow = true;
}

void	ScalarConverter::_convertLiteralToDouble(const std::string literal) {
	char* 		endptr;
	_double = strtod(literal.c_str(), &endptr);

	if (_double < _charMin || _double > _charMax)
		_charOverflow = true;
}

// ------------------------------ Casts from Type ------------------------------
void	ScalarConverter::_castFromChar(void) {
	_int = static_cast<char>( _char );
	_float = static_cast<float>( _char );
	_double = static_cast<double>( _char );
}

void	ScalarConverter::_castFromInt(void) {
	_char = static_cast<char>( _int );
	_float = static_cast<float>( _int );
	_double = static_cast<double>( _int );
	if (!std::isprint(_char))
		_charNotPrintable = true;
	if (_intOverflow)
		_impossibleFloatDouble = true;
}

void	ScalarConverter::_castFromFloat(void) {
	_char = static_cast<char>( _float );
	_int = static_cast<float>( _float );
	_double = static_cast<double>( _float );
	if (!std::isprint(_char))
		_charNotPrintable = true;
}

void	ScalarConverter::_castFromDouble(void) {
	_char = static_cast<char>( _double );
	_int = static_cast<double>( _double );
	_float = static_cast<float>( _double );
	if (!std::isprint(_char))
		_charNotPrintable = true;
}

void	ScalarConverter::_castFromLiteral(const std::string literal) {
	if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
	{
		_float = std::numeric_limits<float>::infinity();
		_double = std::numeric_limits<double>::infinity();
	}
	if (literal == "-inf" || literal == "-inff")
	{
		_float = (-1) * std::numeric_limits<float>::infinity();
		_double = (-1) * std::numeric_limits<double>::infinity();
	}
	if (literal == "nan" || literal == "nanf")
	{
		_float = std::numeric_limits<float>::quiet_NaN();
		_double = std::numeric_limits<double>::quiet_NaN();
	}
}

// ------------------------------ Print Elements -------------------------------
void	ScalarConverter::_printConversion(void) {
	ScalarConverter::_printChar();
	ScalarConverter::_printInt();
	ScalarConverter::_printFloat();
	ScalarConverter::_printDouble();
}

void	ScalarConverter::_printChar(void) {
	std::cout << "char: ";
	if (_charOverflow)
		std::cout << "impossible";
	else if (_charNotPrintable)
		std::cout << "non displayable";
	else
		std::cout << "'" << _char << "'";
	std::cout << std::endl;
}

void	ScalarConverter::_printInt(void) {
	std::cout << "int: ";
	if (_intOverflow)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int << std::endl;
}

void	ScalarConverter::_printFloat(void) {
	std::cout << "float: ";
	if (_impossibleFloatDouble)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (_float == static_cast< int >( _float ) )
		std::cout << _float << ".0f" << std::endl;
	else
		std::cout << _float << "f" << std::endl;
}

void	ScalarConverter::_printDouble(void) {
	std::cout << "double: ";
	if (_impossibleFloatDouble)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << _double;
	if (_double == static_cast< int >( _double ))
		std::cout << ".0" << std::endl;
}

/* ************************************************************************** */
/*                                EXCEPTIONS                                  */
/* ************************************************************************** */

const char*	ScalarConverter::InvalidLiteral::what(void) const throw () {
	return ("Invalid Literal.\nUsage: should be a char, a int, a float or a double");
}
