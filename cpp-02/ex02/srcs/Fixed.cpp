/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:49:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/23 11:06:00 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "../includes/Fixed.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Fixed::Fixed(void) {
	// std::cout << "Default constructor called" << std::endl;
	this->_fixedValue = 0;
}

Fixed::Fixed(const Fixed& fixed) {
	// std::cout << "Copy constructor called" << std::endl;
	this->operator=(fixed);
}

Fixed::Fixed(const int nb) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = nb * (1 << this->_nbFractionalBits);
}

Fixed::Fixed(const float nb) {
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = (roundf(nb * (1 << this->_nbFractionalBits)));
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
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

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
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
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Fixed&	Fixed::operator=(const Fixed& rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedValue = rhs.getRawBits();
	return (*this);
}

// ------------------------------- Arithmetic ------------------------------- //
Fixed	Fixed::operator+(const Fixed& rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& rhs) const {
	if (rhs._fixedValue == 0)
	{
		std::cout << "Error: You can't divide by 0" << std::endl;
		return (Fixed());
	}
	return (Fixed(this->_fixedValue / rhs._fixedValue));
}

// ------------------------------- Comparison ------------------------------- //
bool	Fixed::operator>(const Fixed& rhs) const {
	return (this->_fixedValue > rhs._fixedValue);
}

bool	Fixed::operator<(const Fixed& rhs) const {
	return (this->_fixedValue < rhs._fixedValue);
}

bool	Fixed::operator>=(const Fixed& rhs) const {
	return (this->_fixedValue >= rhs._fixedValue);
}

bool	Fixed::operator<=(const Fixed& rhs) const {
	return (this->_fixedValue <= rhs._fixedValue);
}

bool	Fixed::operator==(const Fixed& rhs) const {
	return (this->_fixedValue == rhs._fixedValue);
}

bool	Fixed::operator!=(const Fixed& rhs) const {
	return (this->_fixedValue != rhs._fixedValue);
}

// ------------------- Incrementation / Decrementation --------------------- //

Fixed&	Fixed::operator++(void) {
	this->_fixedValue++;
	return (*this);
}

Fixed&	Fixed::operator--(void) {
	this->_fixedValue--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	this->_fixedValue++;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	this->_fixedValue--;
	return (tmp);
}

// ------------------------------ Redirection ------------------------------- //

std::ostream&	operator<<(std::ostream& oS, const Fixed& rhs) {
	oS << rhs.toFloat();
	return (oS);
}