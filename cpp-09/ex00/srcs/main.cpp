/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:30:59 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/12 17:33:10 by aaugu            ###   ########.fr       */
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

	BitcoinExchange	btc;

	btc.bitcoinValues(inputFile);

	return (0);
}
