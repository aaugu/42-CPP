/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:12:17 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 16:53:49 by aaugu            ###   ########.fr       */
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
	std::cout << "[Cat] Destructor called." << std::endl;
	delete this->_brain;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Cat&	Cat::operator=(const Cat& src)
{
	std::cout << "[Cat] Copy assignment overload operator called." << std::endl;
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

void	Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

Brain*	Cat::getBrain() {
	return (this->_brain);
}
