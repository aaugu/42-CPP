/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:11:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 11:23:11 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/WrongAnimal.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void) : _type("Chocobo") {
	std::cout << "[Wrong Animal] Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "[Wrong Animal] Argument constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << "[Wrong Animal] Copy constructor called." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "[Wrong Animal] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "[Wrong Animal] Copy assignment overload operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	WrongAnimal::makeSound(void) const {
	std::cout << "Kweh" << std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string	WrongAnimal::getType() const {
	return (this->_type);
}
