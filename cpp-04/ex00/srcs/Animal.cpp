/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:11:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 11:14:43 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Animal.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Animal::Animal(void) : _type("Chocobo") {
	std::cout << "[Animal] Default constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "[Animal] Argument constructor called." << std::endl;
}

Animal::Animal(const Animal& src) {
	std::cout << "[Animal] Copy constructor called." << std::endl;
	*this = src;
}

Animal::~Animal(void) {
	std::cout << "[Animal] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Animal&	Animal::operator=(const Animal& src)
{
	std::cout << "[Animal] Copy assignment overload operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	Animal::makeSound(void) const {
	std::cout << "Kweh" << std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string	Animal::getType() const {
	return (this->_type);
}
