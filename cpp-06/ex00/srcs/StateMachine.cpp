/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StateMachine.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:47:43 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/20 16:43:17 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/StateMachine.hpp"
#include <iostream>

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

StateMachine::StateMachine(void) {}

StateMachine::StateMachine(const StateMachine& src) { *this = src; }

StateMachine::~StateMachine(void) {}

StateMachine&	StateMachine::operator=(const StateMachine& src) {
	(void) src;
	return (*this);
}

/* ************************************************************************** */
/*                           PUBLIC MEMBER FUNCTION                           */
/* ************************************************************************** */

int	StateMachine::findLiteralType(const std::string& literal) {
	int	state = IDLE;
	int type = UNKNOWN;

	for (int i = 0; (size_t)i <= literal.length(); i++)
	{
		if (state == ERROR)
			break ;
		execStateMachine(literal[i], state, type);
		// std::cout << "char : " << literal[i] << " / type: " << type << " / state: " << state << std::endl;
	}
	return (type);
}

/* ************************************************************************** */
/*                          PRIVATE MEMBER FUNCTION                           */
/* ************************************************************************** */
// ------------------------ State Machine execution ----------------------------
void	StateMachine::execStateMachine(const char c, int& state, int& type) {
	switch (state)
	{
		case IDLE:
			stateIdle(c, state);
			break;
		case SIGN:
			stateSign(c, state, type);
			break;
		case sCHAR:
			stateChar(c, state, type);
			break;
		case sNUM:
			stateNum(c, state, type);
			break;
		case sDOUBLE:
			stateDouble(c, state, type);
			break;
		case sFLOAT:
			stateFloat(c, state, type);
			break;
	}
}

// ---------------------------------- States ----------------------------------
void	StateMachine::stateIdle(const char c, int& state) {
	if (c == '\0')
		state = ERROR;
	else if (c == '-' || c == '+')
		state = SIGN;
	else if (std::isdigit(c))
		state = sNUM;
	else
		state = sCHAR;
}

void	StateMachine::stateChar(const char c, int& state, int& type) {
	if (c == '\0')
		type = CHAR;
	else
		state = ERROR;
}

void	StateMachine::stateSign(const char c, int& state, int& type) {
	if (c == '\0')
		type = CHAR;
	else if (std::isdigit(c))
		state = sNUM;
	else
		state = ERROR;
}

void	StateMachine::stateNum(const char c, int& state, int& type) {
	if (c == '\0')
		type = INT;
	else if (std::isdigit(c))
		return ;
	else if (c == '.')
		state = sDOUBLE;
	else
		state = ERROR;
}

void	StateMachine::stateDouble(const char c, int& state, int& type) {
	if (c == '\0')
		type = DOUBLE;
	else if (std::isdigit(c))
		return ;
	else if (c == 'f')
		state = sFLOAT;
	else
		state = ERROR;
}

void	StateMachine::stateFloat(const char c, int& state, int& type) {
	if (c == '\0')
		type = FLOAT;
	else
		state = ERROR;
}
