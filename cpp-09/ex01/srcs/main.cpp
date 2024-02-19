/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:19:43 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/19 13:21:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/RPN.hpp"

# define RED  "\e[31m"
# define CYAN "\e[96m"
# define END  "\e[0m"

int	main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout	<< CYAN "Usage: ./RPN <Reverse_Polish_Notation_Expression>" END 
					<< std::endl;
		return (1);
	}

	RPN	rpn;
	try	{
		std::cout << rpn.calculateRPN(av[1]) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << END << std::endl;
		return (1);
	}

	return (0);
}
