/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:24:57 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/15 10:31:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/FragTrap.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " recruited." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " recruited." << std::endl;
}

FragTrap::FragTrap(FragTrap& fragTrap) : ClapTrap(fragTrap) {
	this->operator=(fragTrap);
	std::cout << "FragTrap " << this->_name << " cloned." << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->_name << " dismissed." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout	<< "FragTrap " << this->_name << " is kind of doing high five with the ground"
					<< "because he is dead." << std::endl;
		return ;
	}
	this->healthBuff = true;
	std::cout	<< "FragTrap " << this->_name
				<< " raise hands for high five 'I love you guys'. "
				<< "No one returns it but you get a health regen bonus !"
				<< std::endl;
}
