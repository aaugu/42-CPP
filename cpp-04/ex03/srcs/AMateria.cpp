/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:06:04 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:12:01 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/AMateria.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

AMateria::AMateria(void) {
	std::cout << "[AMateria] Default constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& src) {
	std::cout << "[AMateria] Copy constructor called." << std::endl;
	*this = src;
}

AMateria::~AMateria(void) {
	std::cout << "[AMateria] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
