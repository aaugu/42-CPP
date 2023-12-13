/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:54:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/13 15:47:16 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) : 	_name("No name"), _hitPoints(10),
							_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " recruited." << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_name(name), _hitPoints(10),
										_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " recruited." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& clapTrap) {
	this->operator=(clapTrap);
	std::cout << "ClapTrap " << this->_name << " cloned." << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " dismissed." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << ERR_ATTACK_DEAD << std::endl;
		return ;
	}

	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << ERR_ATTACK_ENERGY << std::endl;
		return ;
	}

	this->_energyPoints--;
	std::cout 	<< "ClapTrap " << this->_name << " attacks " << target
				<< " causing " << this->_attackDamage << " points of damage"
				<< " and has now " << this->_energyPoints << " energy points left."
				<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << ERR_DAMAGE_DEAD << std::endl;
		return ;
	}

	if (amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout	<< "ClapTrap " << this->_name << " receives " << amount << " point(s) of damage"
					<< " and is now dead." << std::endl;
	}
	else if (amount == 0)
	{
		std::cout	<< "Congratulations ClapTrap " << this->_name << ", you dodged!"
					<< " You have " << this->_hitPoints << " HP left."
					<< std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout	<< "ClapTrap " << this->_name
					<< " receives " << amount << " point(s) of damage"
					<< " and has now " << this->_hitPoints << " HP left." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << ERR_HEAL_DEAD << std::endl;
		return ;
	}

	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << ERR_HEAL_ENERGY << std::endl;
		return ;
	}

	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout	<< "ClapTrap " << this->_name
				<< " heals himself for " << amount << " point(s) of HP (" << this->_hitPoints << "HP left)"
				<< " and has now " << this->_energyPoints << " energy point(s) left."
				<< std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}
