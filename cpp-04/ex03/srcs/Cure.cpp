/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:36:30 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 11:14:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Cure.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Cure::Cure(void) : type_("ice") {
	std::cout << "[Cure] Default constructor called." << std::endl;
}

Cure::Cure(const Cure& src) {
	std::cout << "[Cure] Copy constructor called." << std::endl;
	*this = src;
}

Cure::~Cure(void) {
	std::cout << "[Cure] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Cure&	Cure::operator=(const Cure& src)
{
	std::cout << "[Cure] Copy assignment overload operator called." << std::endl;
	if (this != &src)
	{
		
	}
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	Cure::use(ICharacter& target) {
	std::cout << "* heals" << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone() const {
	AMateria*	cureClone = new Cure();

	return (cureClone);
}