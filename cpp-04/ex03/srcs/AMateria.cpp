/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:06:04 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 15:09:56 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/AMateria.hpp"
#include "../includes/Colors.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

AMateria::AMateria(void) {
	std::cout << BLUE "[AMateria] Default constructor called." END << std::endl;
}

AMateria::AMateria(std::string const & type) : type_(type) {
	std::cout << BLUE "[AMateria] Argument constructor called." END << std::endl;
}

AMateria::AMateria(const AMateria& src) {
	std::cout << BLUE "[AMateria] Copy constructor called." END << std::endl;
	*this = src;
}

AMateria::~AMateria(void) {
	std::cout << BLUE "[AMateria] Destructor called." END << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
AMateria&	AMateria::operator=(const AMateria& src)
{
	std::cout << BLUE "[AMateria] Copy assignment overload operator called." << std::endl;
	if (this != &src)
		this->type_ = src.getType();
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	AMateria::use(ICharacter& target) {
	std::cout	<< BLUE  "* uses unknown materia against " << target.getName() << " *" END
				<< std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string& AMateria::getType(void) const {
	return (this->type_);
}