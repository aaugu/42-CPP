/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:44:17 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/30 09:48:14 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>
#include "../includes/Span.hpp"

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

Span::Span(void) : _size(0),_range() {}

Span::Span(unsigned int size) : _size(size), _range() {}

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

void	Span::addNumber(int num) {
	if (_size == 0)
		throw std::out_of_range("Cannot fill a span of size 0.\n");
	if (_range.size() < _size)
		_range.push_back(num);
	else
		throw std::out_of_range("Span is already full.\n");
}

int	Span::shortestSpan(void) const {
	if (_range.size() <= 1)
		throw Span::NotEnoughArguments();

	std::vector<int> range = _range;
	std::sort(range.begin(), range.end());

	int	shortestSpan = *std::max_element(range.begin(), range.end());
	int	test;
	std::vector<int>::const_iterator it;
    for (it = range.begin(); it < range.end(); it++)
	{
		test = abs(*(it + 1) - *it);
		if (test < shortestSpan)
			shortestSpan = test;
	}

	return (shortestSpan);
}

int	Span::longestSpan(void) const {
	if (_range.size() <= 1)
		throw Span::NotEnoughArguments();

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
	std::vector<int>::const_iterator it;
    for (it = src.getRange().begin(); it != src.getRange().end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
    return (os);
}

/* ************************************************************************** */
/*                                 EXCEPTIONS                                 */
/* ************************************************************************** */

const char *	Span::NotEnoughArguments::what(void) const throw () {
	return ("Not enough elements to be compared");
};
