/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:35:47 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/19 11:44:32 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "../includes/RPN.hpp"

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

RPN::RPN(void) {}

RPN::RPN(const RPN& src) : _elements(src._elements) {}

RPN::~RPN(void) {}

RPN&	RPN::operator=(const RPN& src) {
	this->_elements = src._elements;
	return ( *this );
}

/* ************************************************************************** */
/*                          PUBLIC MEMBER FUNCTIONS                           */
/* ************************************************************************** */

int	RPN::calculateRPN(std::string input)
{
	_reinitializeStack();
	_checkInput(input);

	for ( std::string::iterator it = input.begin(); it != input.end(); it++ )
	{
		if ( _isOperand(*it) )
			_elements.push(*it - '0');
		else if ( _isOperator(*it) )
			_setIntermediateResult(*it);
	}

	if ( _elements.size() != 1 )
		throw std::runtime_error("invalid input : one operand or operator is missing");

	return (_elements.top());
}

/* ************************************************************************** */
/*                          PRIVATE MEMBER FUNCTIONS                          */
/* ************************************************************************** */

void	RPN::_reinitializeStack(void)
{
	while ( _elements.empty() == false)
		_elements.pop();
}

void	RPN::_checkInput(std::string input)
{
	std::string	legitElements = "0123456798 +-*/";

	for ( std::string::iterator it = input.begin(); it != input.end(); it++ )
	{
		if (legitElements.find(*it) == std::string::npos)
			throw std::runtime_error("invalid input: can only contain " + legitElements);
	}
}

bool	RPN::_isOperand(char c) {
	return ( std::isdigit(c) );
}

bool	RPN::_isOperator(char c) {
	std::string operators = "+-*/";

	if (operators.find(c) != std::string::npos)
		return (true);
	return (false);
}

void	RPN::_setIntermediateResult(char operatorType)
{
	if (_elements.empty() || _elements.size() < 2)
		throw std::runtime_error("invalid input : one operand or operator is missing");

	int	b = _elements.top();
	_elements.pop();
	int	a = _elements.top();
	_elements.pop();

	int result = _makeOperation(a, b, operatorType);
	_elements.push(result);
}

int	RPN::_makeOperation(int a, int b, char operatorType)
{
	switch (operatorType)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			return (_divideOperation(a, b));

		default:
		{
			std::stringstream ss;
			ss << operatorType << ": invalid operator";
			throw std::runtime_error(ss.str());
		}
	}

}

int	RPN::_divideOperation(int a, int b)
{
	if (b == 0)
	{
		std::stringstream ss;
		ss << a << " / " << b << ": cannot divide by 0";
		throw std::runtime_error(ss.str());
	}
	return (a / b);
}
