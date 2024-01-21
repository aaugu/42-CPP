/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:24:18 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/21 16:07:55 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/StateMachine.hpp"
#include "../includes/ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./convert <literal>" << std::endl;
		return (1);
	}
	try {
		ScalarConverter::convert(av[1]);
	}
	catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}

	// std::cout << std::endl << std::endl;
	// std::cout << "Char min:   " << std::numeric_limits<char>::min() << std::endl;
	// std::cout << "Char max:   " << std::numeric_limits<char>::max() << std::endl;
	// std::cout << "Int min:    " << std::numeric_limits<int>::min() << std::endl;
	// std::cout << "Int max:    " << std::numeric_limits<int>::max() << std::endl;
	// std::cout << "Float min:  " << std::numeric_limits<float>::min() << std::endl;
	// std::cout << "Float max:  " << std::numeric_limits<float>::max() << std::endl;
	// std::cout << "Double min: " << std::numeric_limits<double>::min() << std::endl;
	// std::cout << "Double max: " << std::numeric_limits<double>::max() << std::endl << std::endl;

	// std::cout << "Float infinity:  " << std::numeric_limits<float>::infinity() << std::endl;
	// std::cout << "Double infinity: " << std::numeric_limits<double>::infinity() << std::endl;
	// std::cout << "Float NaN:       " << std::numeric_limits<float>::quiet_NaN() << std::endl;
	// std::cout << "Double NaN:      " << std::numeric_limits<double>::quiet_NaN() << std::endl;

	return (0);
}
