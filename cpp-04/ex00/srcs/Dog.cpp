/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:12:25 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 11:27:07 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Dog.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Dog::Dog(void) : Animal() {
	std::cout << "[Dog] Default constructor called." << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& src) : Animal() {
	std::cout << "[Dog] Copy constructor called." << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	std::cout << "[Dog] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Dog&	Dog::operator=(const Dog& src)
{
	std::cout << "[Dog] Copy assignment overload operator called." << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}


/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}
