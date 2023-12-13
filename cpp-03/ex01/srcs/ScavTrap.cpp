/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:20:34 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/13 12:27:16 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ScavTrap.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_gateGuarding = false;
	std::cout << "ScavTrap " << this->_name << " recruited." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_gateGuarding = false;
	std::cout << "ScavTrap " << this->_name << " recruited." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& scavTrap) : ClapTrap(scavTrap) {
	this->operator=(scavTrap);
	std::cout << "ScavTrap " << this->_name << " cloned." << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " dismissed." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
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

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << ERR_ATTACK_DEAD << std::endl;
		return ;
	}

	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << ERR_ATTACK_ENERGY << std::endl;
		return ;
	}

	this->_energyPoints--;
	std::cout 	<< "ScavTrap " << this->_name << " attacks " << target
				<< " causing " << this->_attackDamage << " points of damage"
				<< " and has now " << this->_energyPoints << " energy points left."
				<< std::endl;
}

void	ScavTrap::guardGate(void)
{
	this->_gateGuarding = true;
	std::cout	<< "ScavTrap " << this->_name << " is now guarding the Crystal Tower Gate."
				<< std::endl;
}
