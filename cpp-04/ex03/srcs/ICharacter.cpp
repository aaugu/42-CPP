/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:06:02 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:11:24 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ICharacter.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

ICharacter::ICharacter(void) {
	std::cout << "[ICharacter] Default constructor called." << std::endl;
}

ICharacter::ICharacter(const ICharacter& src) {
	std::cout << "[ICharacter] Copy constructor called." << std::endl;
	*this = src;
}

ICharacter::~ICharacter(void) {
	std::cout << "[ICharacter] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
