/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:32:10 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/16 12:32:24 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

ScalarConverter::ScalarConverter(void)
		:	toChar_(""),
			toInt_(0),
			toFloat_(0),
			toDouble_(0),
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
		this->toChar_ = src.toChar_;
		this->toInt_ = src.toInt_;
		this->toFloat_ = src.toFloat_;
		this->toDouble_ = src.toDouble_;
		this->type_ = src.type_;
	}
	return (*this);
}

/* ************************************************************************** */
/*                           PUBLIC MEMBER FUNCTION                           */
/* ************************************************************************** */

void	convert(const std::string literal) {

}
