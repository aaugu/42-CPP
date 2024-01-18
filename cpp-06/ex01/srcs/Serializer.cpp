/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:43:42 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/18 15:54:22 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.hpp"

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& src) { *this = src; }

Serializer::~Serializer(void) {}

Serializer&	Serializer::operator=(const Serializer& src) {
	(void) src;
	return (*this);
}

/* ************************************************************************** */
/*                           PUBLIC MEMBER FUNCTION                           */
/* ************************************************************************** */

uintptr_t	Serializer::serialize(Data* ptr) {
	return ( reinterpret_cast< uintptr_t >(ptr) );
}

Data*		Serializer::deserialize(uintptr_t raw) {
	return ( reinterpret_cast< Data * >(raw) );
}
