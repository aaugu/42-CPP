/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:36:30 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 16:11:54 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Cure.hpp"
#include "../includes/Colors.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Cure::Cure(void) : AMateria("cure") {
	std::cout << GREEN "[Cure] Default constructor called." END << std::endl;
}

Cure::Cure(const Cure& src) : AMateria("cure") {
	std::cout << GREEN "[Cure] Copy constructor called." END << std::endl;
	*this = src;
}

Cure::~Cure(void) {
	std::cout << GREEN "[Cure] Destructor called." END << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Cure&	Cure::operator=(const Cure& src)
{
	std::cout << GREEN "[Cure] Copy assignment overload operator called." END << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

AMateria*	Cure::clone() const {
	AMateria*	cureClone = new Cure();
	return (cureClone);
}

void	Cure::use(ICharacter& target) {
	std::cout << GREEN "* heals " << target.getName() << "'s wounds *" END << std::endl;
}