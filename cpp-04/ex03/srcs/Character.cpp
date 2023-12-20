/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:34:26 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:34:49 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../includes/Character.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Character::Character(void) {
	std::cout << "[Character] Default constructor called." << std::endl;
}

Character::Character(const Character& src) {
	std::cout << "[Character] Copy constructor called." << std::endl;
	*this = src;
}

Character::~Character(void) {
	std::cout << "[Character] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
