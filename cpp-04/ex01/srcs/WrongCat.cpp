/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:12:17 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 11:34:53 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/WrongCat.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "[Wrong Cat] Default constructor called." << std::endl;
	this->_type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal() {
	std::cout << "[Wrong Cat] Copy constructor called." << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void) {
	std::cout << "[Wrong Cat] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	std::cout << "[Wrong Cat] Copy assignment overload operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	WrongCat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}
