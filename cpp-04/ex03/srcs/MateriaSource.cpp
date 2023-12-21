/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:36:21 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 10:26:05 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/MateriaSource.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

MateriaSource::MateriaSource(void) {
	std::cout << "[MateriaSource] Default constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	std::cout << "[MateriaSource] Copy constructor called." << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void) {
	std::cout << "[MateriaSource] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
MateriaSource&	MateriaSource::operator=(const MateriaSource& src)
{
	std::cout << "[MateriaSource] Copy assignment overload operator called." << std::endl;
	if (this != &src)
	{
		
	}
	return (*this);
}