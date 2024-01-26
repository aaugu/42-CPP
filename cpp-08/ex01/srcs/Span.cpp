/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:44:17 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/26 14:36:01 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include "../includes/Span.hpp"

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

Span::Span(void) : _N(0) {
	_vector.resize(_N);
}

Span::Span(unsigned int size) : _N(size) {
	_vector.resize(_N);
}

Span::Span(Span& src) : _N(src._N) {
	_vector.erase(copy(	src._vector.begin(), src._vector.end(), _vector.begin()), _vector.end());
	_vector.resize(_N);
}

Span::~Span(void) {}

Span&	Span::operator=(const Span& src) {
	(void) src;
	return (*this);
}

/* ************************************************************************** */
/*                           PUBLIC MEMBER FUNCTION                           */
/* ************************************************************************** */

void	Span::addNumber(unsigned int num) {
	if (_vector.size() >= static_cast< unsigned long >(_N))
		_vector.push_back(num);
	else
		throw std::out_of_range("Span is already full.");
}

unsigned int	Span::shortestSpan() const {
	// std::sort(_vector.begin(), _vector.end());
	return (1);
}

unsigned int	Span::longestSpan() const {
	if (_vector.empty() || _vector.size() == 1)
		throw std::invalid_argument("Not enough elements to be compared");

	return ( std::max_element(_vector.begin(), _vector.end())
			 - std::min_element(_vector.begin(), _vector.end()) );
}

/* ************************************************************************** */
/*                                 ACCESSORS                                  */
/* ************************************************************************** */

std::vector<unsigned int>	Span::getVector() {
	return (this->_vector);
}