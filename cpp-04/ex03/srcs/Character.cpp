/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:34:26 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 11:10:13 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../includes/Character.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Character::Character(void) : name_("No name") {
	std::cout << "[Character] Default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias_[i] = NULL;
}

Character::Character(const std::string name) : name_(name) {
	std::cout << "[Character] Argument constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias_[i] = NULL;s
}

Character::Character(const Character& src) {
	std::cout << "[Character] Copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias_[i] = NULL;
	*this = src;
}

Character::~Character(void) {
	std::cout << "[Character] Destructor called." << std::endl;
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
		for (int i = 0; i < 4; i++)
		{
			if (this->materias_[i] != NULL)
				delete this->materias_[i];
			this->materias_[i] = new AMateria(*src.materias_[i]);

		}
			this->materias_[i] = src.getMateriaById(i);
	}
	return (*this);
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string& Character::getName(void) const {
	return (this->name_);
}