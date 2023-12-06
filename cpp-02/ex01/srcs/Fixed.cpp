/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:49:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/20 15:04:10 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

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
	this->_fixedValue = nb * (1 << this->_nbFractionalBits);
}

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