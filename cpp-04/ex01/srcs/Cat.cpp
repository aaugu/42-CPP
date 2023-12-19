/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:12:17 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 12:28:27 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Cat.hpp"
#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Cat::Cat(void) : Animal() {
	std::cout << "[Cat] Default constructor called." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(const Cat& src) : Animal() {
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
		this->_type = src.getType();
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}
