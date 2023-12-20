/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:38:01 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 16:26:49 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Brain.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Brain::Brain(void) {
	for (unsigned int i = 0; i < 100; i++)
		this->_ideas[i] = "";
	std::cout << "[Brain] Default constructor called." << std::endl;
}

Brain::Brain(const Brain& src) {
	std::cout << "[Brain] Copy constructor called." << std::endl;
	*this = src;
}

Brain::~Brain(void) {
	std::cout << "[Brain] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
Brain&	Brain::operator=(const Brain& src)
{
	std::cout << "[Brain] Copy assignment overload operator called." << std::endl;
	if (this != &src)
	{
		for (unsigned int i = 0; i < 100; i++)
			this->_ideas[i] = src.getIdeabyId(i);
	}
	return (*this);
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

std::string	Brain::getIdeabyId(int i) const {
	if (i < 0 || i >= 100)
	{
		std::cout << "Idea out of range of the brain";
		return "";
	}
	return (this->_ideas[i]);
}

void	Brain::setIdeabyId(const std::string idea, int i) {
	if (i < 0 || i >= 100)
	{
		std::cout << "Idea out of range of the brain";
		return ;
	}
	this->_ideas[i] = idea;
}
