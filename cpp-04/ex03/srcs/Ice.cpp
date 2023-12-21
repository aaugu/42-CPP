/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:36:28 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 16:58:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Ice.hpp"
#include "../includes/Colors.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Ice::Ice(void) : AMateria("ice") {
	std::cout << CYAN "[Ice] Default constructor called." END << std::endl;
}

Ice::Ice(const Ice& src) : AMateria("ice") {
	std::cout << CYAN "[Ice] Copy constructor called." END << std::endl;
	*this = src;
}

Ice::~Ice(void) {
	std::cout << CYAN "[Ice] Destructor called." END << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Ice&	Ice::operator=(const Ice& src)
{
	std::cout << CYAN "[Ice] Copy assignment overload operator called." END << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

AMateria*	Ice::clone() const {
	AMateria*	iceClone = new Ice();
	return (iceClone);
}

void	Ice::use(ICharacter& target) {
	std::cout << CYAN "* shoots an ice bolt at " << target.getName() << " *" END << std::endl;
}