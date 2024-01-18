/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:32:10 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/17 17:19:59 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ScalarConverter.hpp"

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
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& oS, const ScalarConverter& src) {
	(void) src;
	return (oS);
}

/* ************************************************************************** */
/*                           PUBLIC MEMBER FUNCTION                           */
/* ************************************************************************** */

void	ScalarConverter::convert(const std::string literal) {

	int	type_ = StateMachine::getLiteralTypeFromStateMachine(literal);
	if (type_ == UNKNOWN)
		throw ScalarConverter::InvalidLiteral();
	std::cout << type_ << std::endl;
}

/* ************************************************************************** */
/*                          PRIVATE MEMBER FUNCTION                           */
/* ************************************************************************** */



/* ************************************************************************** */
/*                                EXCEPTIONS                                  */
/* ************************************************************************** */

const char*	ScalarConverter::InvalidLiteral::what(void) const throw () {
	return ("Invalid Literal.\nUsage: should be a char, a int, a float or a double");
}
