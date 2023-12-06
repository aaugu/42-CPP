/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:54:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/17 11:03:35 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTOR & DESTRUCTOR                          */
/* ************************************************************************** */

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	typedef void (Harl::*Complains)(void);
	Complains	complains[4] = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(levels[i]) == 0)
		{
			(this->*complains[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

/* ************************************************************************** */
/*                              PRIVATE FUNCTIONS                             */
/* ************************************************************************** */

void	Harl::_debug(void)
{
	std::cout 	<< "[ DEBUG ] " << std::endl
				<< "I love having extra bacon for my "
				"7XL-double-cheese-triple-pickle-special-ketchup burger. "
				"I really do!"
				<< std::endl;
}

void	Harl::_info(void)
{
	std::cout 	<< "[ INFO ] " << std::endl
				<< "I cannot believe adding extra bacon costs more money. "
				"You didn't put enough bacon in my burger! "
				"If you did, I wouldn't be asking for more!" 
				<< std::endl;
}

void	Harl::_warning(void)
{
	std::cout 	<< "[ WARNING ] " << std::endl
				<< "I think I deserve to have some extra bacon for free. "
				"I’ve been coming for years whereas you started working "
				"here since last month."
				<< std::endl;
}

void	Harl::_error(void)
{
	std::cout 	<< "[ ERROR ] " << std::endl
				<< "This is unacceptable! "
				"I want to speak to the manager now."
				<< std::endl;
}