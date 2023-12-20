/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:11:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 16:55:17 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/AAnimal.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

AAnimal::AAnimal(void) : _type("Chocobo") {
	std::cout << "[Animal] Default constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "[Animal] Argument constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) {
	std::cout << "[Animal] Copy constructor called." << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void) {
	std::cout << "[Animal] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
AAnimal&	AAnimal::operator=(const AAnimal& src)
{
	std::cout << "[Animal] Copy assignment overload operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	AAnimal::makeSound(void) const {
	std::cout << "Kweh" << std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string	AAnimal::getType() const {
	return (this->_type);
}
