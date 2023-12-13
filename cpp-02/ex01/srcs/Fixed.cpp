/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:49:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/08 15:29:16 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "../includes/Fixed.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedValue = 0;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(fixed);
}

Fixed::Fixed(const int nb) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = nb << this->_nbFractionalBits;
}

/* The roundf() function returns x rounded to the nearest integer n , rounding
halfway cases away from zero, regardless of the current rounding direction

Floating point numbers don't have bits at the level of value-representation, 
which is why you can't apply bitwise operations to them
*/
Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = (roundf(nb * (1 << this->_nbFractionalBits)));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

Fixed&	Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedValue = rhs.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& oS, const Fixed& rhs) {
	oS << rhs.toFloat();
	return (oS);
}

/* ************************************************************************** */
/*                              GETTERS & SETTERS                             */
/* ************************************************************************** */

int Fixed::getRawBits(void) const {
	return (this->_fixedValue);
}

void Fixed::setRawBits(int const raw) {
	this->_fixedValue = raw;
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

int	Fixed::toInt(void) const {
	return (this->_fixedValue >> this->_nbFractionalBits);
}

float Fixed::toFloat(void) const {
	return ((float)this->_fixedValue / (1 << this->_nbFractionalBits));
}