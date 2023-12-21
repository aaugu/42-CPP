/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:40:27 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/15 10:49:42 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/DiamondTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = ClapTrap::_name;
	ClapTrap::_name = ClapTrap::_name.append("_clap_name");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::getAttackDamage();
	std::cout << "DiamondTrap " << this->_name << " recruited." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getHitPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
	std::cout << "DiamondTrap " << this->_name << " recruited." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& diamondTrap) : ClapTrap(diamondTrap) {
	this->operator=(diamondTrap);
	std::cout << "DiamondTrap " << this->_name << " cloned." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->_name << " dismissed." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
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

void DiamondTrap::whoAmI(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "I was DiamondTrap " << this->_name << std::endl;
		std::cout << "From ClapTrap " << ClapTrap::_name << std::endl;
		return ;
	}
	std::cout << "I am DiamondTrap " << this->_name << std::endl;
	std::cout << "From ClapTrap " << ClapTrap::_name << std::endl;
}