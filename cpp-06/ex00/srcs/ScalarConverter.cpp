/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:32:10 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/17 15:44:14 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ScalarConverter.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

ScalarConverter::ScalarConverter(void)
		:	char_(""),
			int_(0),
			float_(0),
			double_(0),
			type_(UNKNOWN) {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) {
	if (this != &src)
	{
		this->char_ = src.char_;
		this->int_ = src.int_;
		this->float_ = src.float_;
		this->double_ = src.double_;
		this->type_ = src.type_;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& oS, const ScalarConverter& src) {
	oS	<< "char: ";
	oS	<< "int: ";
	oS	<< "float: ";
	oS	<< "double: ";
	return (oS);
}

/* ************************************************************************** */
/*                           PUBLIC MEMBER FUNCTION                           */
/* ************************************************************************** */

void	convert(const std::string literal) {

}

/* ************************************************************************** */
/*                          PRIVATE MEMBER FUNCTION                           */
/* ************************************************************************** */

// ------------------------------- State Machine -------------------------------
void	ScalarConverter::stateMachine(const std::string& literal) {
	for (int i = 0; i < literal.size(); i++)
	{
		if (this->state_ == ERROR)
			break ;
		this->execStateMachine(literal[i]);
		i++;
	}
}

void	ScalarConverter::execStateMachine(const char c) {
	switch (this->state_)
	{
		case IDLE:
			this->stateIdle(c);
			break;
		case CHAR:
			this->stateChar(c);
			break;
		case NEGATIVE:
			this->stateNegative(c);
			break;
		case DOUBLE:
			this->stateDouble(c);
			break;
		case FLOAT:
			this->stateFloat(c);
			break;
	}
}

void	ScalarConverter::stateIdle(const char c) {
	if (c == '\0')
		state_ = ERROR;
	else if (c == '-')
		state_ = NEGATIVE;
	else if (std::isdigit(c))
		state_ = NUM;
	else
		state_ = CHAR;
}

void	ScalarConverter::stateChar(const char c) {
	if (c == '\0')
		type_ = CHAR;
	else
		state_ = ERROR;
}

void	ScalarConverter::stateNegative(const char c) {
	if (c == '\0')
		type_ = CHAR;
	else if (std::isdigit(c))
		state_ = NUM;
	else
		state_ = ERROR;
}

void	ScalarConverter::stateNum(const char c) {
	if (c == '\0')
		type_ = INT;
	else if (std::isdigit(c))
		state_ = NUM;
	else if (c == '.')
		state_ = DOUBLE;
	else
		state_ = ERROR;
}

void	ScalarConverter::stateDouble(const char c) {

}

void	ScalarConverter::stateFloat(char c) {

}
