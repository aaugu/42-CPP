/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:34:26 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/09 15:27:59 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../includes/Character.hpp"
#include "../includes/Colors.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Character::Character(void) : name_("No name") {
	std::cout << YELLOW "[Character] Default constructor called." END << std::endl;
	this->initializeMaterias_();
}

Character::Character(const std::string name) : name_(name) {
	std::cout << YELLOW "[Character] Argument constructor called." END << std::endl;
	this->initializeMaterias_();
}

Character::Character(const Character& src) {
	std::cout << YELLOW "[Character] Copy constructor called." END << std::endl;
	this->initializeMaterias_();
	*this = src;
}

Character::~Character(void) {
	this->deleteMaterias_();
	std::cout << YELLOW "[Character] Destructor called." END << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Character&	Character::operator=(const Character& src)
{
	std::cout << "[Character] Copy assignment overload operator called." << std::endl;
	if (this != &src)
	{
		this->name_ = src.getName();
		this->deleteMaterias_();
		for (int i = 0; i < 4; i++)
		{
			if (src.materias_[i] != NULL)
				this->materias_[i] = (src.materias_[i])->clone();
		}
	}
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void Character::equip(AMateria* m) {
	if (m == NULL)
	{
		std::cout << RED "Error: There is no materia to equip." END << std::endl;
		return ;
	}

	for (int i = 0; i < 4; i++)
	{
		if (this->materias_[i] == NULL)
		{
			this->materias_[i] = m;
			std::cout	<< YELLOW "[Character] successfully equips "
						<< this->materias_[i]->getType() << " materia." END << std::endl;
			return ;
		}
	}
	std::cout << RED "Error: Materia slots of [Character] are already full." END << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		std::cout << RED "Error: Invalid index in [Character] materias." END << std::endl;
	else if (this->materias_[idx])
	{
		std::cout	<< YELLOW "[Character] successfully unequips "
					<< this->materias_[idx]->getType() << " materia "
					<< "and it is left on the floor" END << std::endl;
		this->materias_[idx] = NULL;
	}
	else
		std::cout << RED "Error: Slot of materia is already empty." END << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4)
		std::cout << RED "Error: Invalid index in [Character] materias." END << std::endl;
	else if (this->materias_[idx])
		this->materias_[idx]->use(target);
	else
		std::cout << RED "Error: Slot of materia is empty." END << std::endl;
}

/* ************************************************************************** */
/*                             PRIVATE FUNCTIONS                              */
/* ************************************************************************** */

void	Character::initializeMaterias_(void)
{
	for (int i = 0; i < 4; i++)
		this->materias_[i] = NULL;
}

void	Character::deleteMaterias_(void)
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

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string& Character::getName(void) const {
	return (this->name_);
}
