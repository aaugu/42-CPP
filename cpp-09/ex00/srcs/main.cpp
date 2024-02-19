/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:30:59 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/19 13:31:51 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cout << CYAN "Usage: ./btc [inputFile]" END << std::endl;
		return (1);
	}

	std::string	inputFile;
	if (ac == 1)
		inputFile = "";
	else
		inputFile = av[1];

	try {
		BitcoinExchange	btc;
		btc.bitcoinValues(inputFile);
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << END << std::endl;
		return (1);
	}

	return (0);
}
