/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:36:21 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/09 15:04:57 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Colors.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

MateriaSource::MateriaSource(void) {
	std::cout << PURPLE "[MateriaSource] Default constructor called." END << std::endl;
	this->initializeMaterias_();
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	std::cout << PURPLE "[MateriaSource] Copy constructor called." END << std::endl;
	this->initializeMaterias_();
	*this = src;
}

MateriaSource::~MateriaSource(void) {
	this->deleteMaterias_();
	std::cout << PURPLE "[MateriaSource] Destructor called." END << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
MateriaSource&	MateriaSource::operator=(const MateriaSource& src)
{
	std::cout << PURPLE "[MateriaSource] Copy assignment overload operator called." END << std::endl;
	if (this != &src)
	{
		this->deleteMaterias_();
		for (int i = 0; i < 4; i++)
		{
			if (src.materias_[i] != NULL)
				this->materias_[i] = src.materias_[i]->clone();
		}
	}
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == NULL)
	{
		std::cout << RED "Error: Invalid materia passed." END << std::endl;
		return ;
	}

	for (int i = 0; i < 4; i++)
	{
		if (this->materias_[i] == NULL)
		{
			this->materias_[i] = materia;
			std::cout 	<< PURPLE "[MateriaSource] learned " << materia->getType()
						<< " materia." END << std::endl;
			return ;
		}
	}
	std::cout	<< RED "Error: MateriaSource cannot learn any more type of materia." END
				<< std::endl;
	delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias_[i] && this->materias_[i]->getType() == type)
		{
			std::cout << PURPLE "[MateriaSource] creating " << type << " materia." END << std::endl;
			return (this->materias_[i]->clone());
		}
	}
	std::cout	<< RED "Error: " << type
				<< " is an unknown type of materia for [MateriaSource]." END
				<< std::endl;
	return (0);
}

/* ************************************************************************** */
/*                             PRIVATE FUNCTIONS                              */
/* ************************************************************************** */

void	MateriaSource::initializeMaterias_(void)
{
	for (int i = 0; i < 4; i++)
		this->materias_[i] = NULL;
}

void	MateriaSource::deleteMaterias_(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias_[i] != NULL)
		{
			delete this->materias_[i];
			this->materias_[i] = NULL;
		}
	}
}
