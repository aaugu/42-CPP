/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:06:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:11:42 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/IMateriaSource.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

IMateriaSource::IMateriaSource(void) {
	std::cout << "[IMateriaSource] Default constructor called." << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& src) {
	std::cout << "[IMateriaSource] Copy constructor called." << std::endl;
	*this = src;
}

IMateriaSource::~IMateriaSource(void) {
	std::cout << "[IMateriaSource] Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

// ---------------------------- Copy assignment ----------------------------- //
