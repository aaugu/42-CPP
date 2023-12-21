/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:36:28 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 10:25:56 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Ice.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Ice::Ice(void) {
	std::cout << "[Ice] Default constructor called." << std::endl;
}

Ice::Ice(const Ice& src) {
	std::cout << "[Ice] Copy constructor called." << std::endl;
	*this = src;
}

Ice::~Ice(void) {
	std::cout << "[Ice] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Ice&	Ice::operator=(const Ice& src)
{
	std::cout << "[Ice] Copy assignment overload operator called." << std::endl;
	if (this != &src)
	{
		
	}
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at" << target.getName() << " *" << std::endl;
}