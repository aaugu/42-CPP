/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:12:17 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 15:00:50 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Cat.hpp"
#include "../includes/AAnimal.hpp"
#include "../includes/Brain.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Cat::Cat(void) : AAnimal() {
	std::cout << "[Cat] Default constructor called." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(const Cat& src) : AAnimal(), _brain(NULL) {
	std::cout << "[Cat] Copy constructor called." << std::endl;
	*this = src;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "[Cat] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Cat&	Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	std::cout << "[Cat] Copy assignment overload operator called." << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

Brain*	Cat::getBrain() {
	return (this->_brain);
}
