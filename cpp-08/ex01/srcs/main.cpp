/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:44:13 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/26 14:31:37 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include "../includes/Span.hpp"

bool	invalidArguments(std::string argument);

int	main(int ac, char **av)
{
	srand(time(NULL));
	
	if (ac != 2 || invalidArguments(av[1]))
	{
		std::cout << "Usage: ./span <unsigned_span_size>" << std::endl;
		return (1);
	}

	int		size = std::stoi(av[1]);
	Span	span(size);

	std::cout << BLUE "Generating collection of numbers :" END << std::endl;
	for (int i = 0; i < size; i++)
	{
		int	n = std::rand() % 42;
		span.addNumber(n);
		std::cout << CYAN << n << " " << END;
	}
	std::cout << std::endl << std::endl;

	std::cout << BLUE "Trying to overflow collection" END << std::endl;
	try {
		span.addNumber(std::rand() % 42);
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Exception: "<< e.what() << END << std::endl;
	}
	std::cout << std::endl << std::endl;

	for (int i = 0; i < size + 1; i++)
		std::cout << (span.getVector())[i] << " ";
	std::cout << std::endl << std::endl;
	
	std::cout << BLUE "Shortest Span:" END << std::endl;
	std::cout << span.shortestSpan() << std::endl << std::endl;
	std::cout << BLUE "Longest Span:" END << std::endl;
	std::cout << span.longestSpan() << std::endl;
	
	return (0);
}

bool	invalidArguments(std::string argument)
{
	int size;
	
	try {
		size = std::stoi(argument);
	}
	catch(const std::invalid_argument& e) {
		std::cerr	<< RED << "Exception: "<< e.what() << END << std::endl;
		return (true);
	}
	catch(const std::out_of_range& e) {
		std::cerr	<< RED << "Exception: "<< e.what() << END << std::endl;
		return (true);
	}
	return ( size < 0 ? true : false );
}