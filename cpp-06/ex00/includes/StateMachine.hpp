/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StateMachine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:40 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/17 16:48:31 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATEMACHINE_HPP
# define STATEMACHINE_HPP

#include <string>

enum states { IDLE, sCHAR, sNUM, sFLOAT, sDOUBLE, NEGATIVE, ERROR };
enum literalTypes { UNKNOWN, CHAR, INT, FLOAT, DOUBLE };

class StateMachine
{
	private:
		// Constructors
		StateMachine(void);
		StateMachine(const StateMachine& src);
		// Destructor
		~StateMachine(void);

		// Overload operator
		StateMachine&	operator=(const StateMachine& src);

		static void	execStateMachine(const char c, int& state, int& type);

		// States
		static void	stateIdle(const char c, int& state);
		static void	stateNegative(const char c, int& state, int& type);
		static void	stateChar(const char c, int& state, int& type);
		static void	stateNum(const char c, int& state, int& type);
		static void	stateDouble(const char c, int& state, int& type);
		static void	stateFloat(const char c, int& state, int& type);

	public:
		// Member functions
		static int	getLiteralTypeFromStateMachine(const std::string& literal);
};

#endif
