/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:44:17 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/27 13:59:39 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include "../includes/Span.hpp"

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

Span::Span(void) : _size(0),_range() {}

Span::Span(unsigned int size) : _size(size), _range(size) {}

Span::Span(Span& src) : _size(src._size), _range(src._range) {}

Span::~Span(void) {}

Span&	Span::operator=(const Span& src) {
	if (this != &src)
	{
		_size = src._size;
		this->_range.clear();
		this->_range.insert(this->_range.end(), src._range.begin(), src._range.end());
	}
	return (*this);
}

/* ************************************************************************** */
/*                           PUBLIC MEMBER FUNCTION                           */
/* ************************************************************************** */

void	Span::addNumber(unsigned int num) {
	if (_range.size() >= static_cast< unsigned long >(_size))
		_range.push_back(num);
	else
		throw std::out_of_range("Span is already full.");
}

unsigned int	Span::shortestSpan() const {
	// std::sort(_range.begin(), _range.end());
	return (1);
}

unsigned int	Span::longestSpan() const {
	if (_range.empty() || _range.size() == 1)
		throw std::invalid_argument("Not enough elements to be compared");

	std::cout	<< "Max: " << *std::max_element(_range.begin(), _range.end())
				<< "Min: " << *std::min_element(_range.begin(), _range.end())
				<< std::endl;
	return ( *std::max_element(_range.begin(), _range.end())
			 - *std::min_element(_range.begin(), _range.end()) );
}

/* ************************************************************************** */
/*                                 ACCESSORS                                  */
/* ************************************************************************** */

const std::vector<int>	Span::getRange() const {
	return (this->_range);
}

/* ************************************************************************** */
/*                             OVERLOAD OPERATOR                              */
/* ************************************************************************** */
std::ostream &	operator<<(std::ostream &os, Span &src)
{
    for (	std::vector<int>::const_iterator it = src.getRange().begin();
			it != src.getRange().end();
			++it)
		std::cout << *it << " ";
	std::cout << std::endl;
    return (os);
}
