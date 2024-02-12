/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:30:59 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/12 16:28:25 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cout << "Usage: ./btc [inputFile]" << std::endl;
		return (1);
	}

	std::string	inputFile;
	if (ac == 1)
		inputFile = "";
	else
		inputFile = av[1];

	try {
		BitcoinExchange	btc;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: "<< e.what() << std::endl;
	}

	return (0);
}
