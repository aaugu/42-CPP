/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:06:04 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 10:59:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/AMateria.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

AMateria::AMateria(void) {
	std::cout << "[AMateria] Default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : type_(type) {
	std::cout << "[AMateria] Argument constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& src) {
	std::cout << "[AMateria] Copy constructor called." << std::endl;
	*this = src;
}

AMateria::~AMateria(void) {
	std::cout << "[AMateria] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
AMateria&	AMateria::operator=(const AMateria& src)
{
	std::cout << "[AMateria] Copy assignment overload operator called." << std::endl;
	if (this != &src)
		this->type_ = src.getType();
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	AMateria::use(ICharacter& target) {
	std::cout	<< "* uses unknown materia against " << target.getName() << " *"
				<< std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string& AMateria::getType(void) const {
	return (this->type_);
}