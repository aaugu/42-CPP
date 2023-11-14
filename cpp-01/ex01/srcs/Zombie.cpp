/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:26:47 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/14 15:42:05 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTOR & DESTRUCTOR                          */
/* ************************************************************************** */

// Default constructor
Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": zombie destroyed" << std::endl;
}

/* ************************************************************************** */
/*                                  SETTERS                                   */
/* ************************************************************************** */

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

/* ************************************************************************** */
/*                             PRIVATE FUNCTIONS                              */
/* ************************************************************************** */

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}