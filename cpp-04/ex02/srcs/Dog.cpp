/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:12:25 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 16:53:55 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Dog.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Dog::Dog(void) : AAnimal() {
	std::cout << "[Dog] Default constructor called." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(const Dog& src) : AAnimal(), _brain(NULL) {
	std::cout << "[Dog] Copy constructor called." << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	std::cout << "[Dog] Destructor called." << std::endl;
	delete this->_brain;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Dog&	Dog::operator=(const Dog& src)
{
	std::cout << "[Dog] Copy assignment overload operator called." << std::endl;
	if (this != &src)
	{
		this->_type = src.getType();
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}


/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

Brain*	Dog::getBrain() {
	return (this->_brain);
}
