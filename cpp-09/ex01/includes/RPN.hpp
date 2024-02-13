/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:34:43 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/13 14:15:43 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int>	_elements;

		// Main function sub functions
		void	_reinitializeStack(void);
		void	_checkInput(std::string input);
		bool	_isOperand(char c);
		bool	_isOperator(char c);
		void	_setIntermediateResult(char operatorType);

		// Operation handling
		int		_makeOperation(int a, int b, char operatorType);
		int		_divideOperation(int a, int b);

	public:
		// Orthodox Canonical Form
		RPN(void);
		RPN(const RPN& src);
		~RPN(void);
		RPN&	operator=(const RPN& src);

		// Public main function
		int	calculateRPN(std::string input);
};

#endif
