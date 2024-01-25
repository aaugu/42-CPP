/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:24:18 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/25 09:55:42 by aaugu            ###   ########.fr       */
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
	return (0);
}
