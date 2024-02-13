/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:19:43 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/13 14:25:09 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/RPN.hpp"

int	main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN <Reverse_Polish_Notation_Expression>" << std::endl;
		return (1);
	}

	RPN	rpn;
	try	{
		std::cout << rpn.calculateRPN(av[1]) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
