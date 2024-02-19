/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:44:13 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/30 13:24:55 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include "../includes/Span.hpp"

bool	invalidArguments(char* argument);
void	testSubject(void);
void	testBase(int size);
void	testAddRange(void);

int	main(int ac, char **av)
{
	srand(time(NULL));

	if (ac != 2 || invalidArguments(av[1]))
	{
		std::cout << "Usage: ./span <unsigned_span_size>" << std::endl;
		return (1);
	}

	int		size = std::atoi(av[1]);

	std::cout << GREEN "TEST SUBJECT" END << std::endl;
	testSubject();
	std::cout << std::endl << GREEN "TEST ADD NUMBER + SHORTEST AND LONGEST SPAN" END << std::endl;
	testBase(size);
	std::cout << std::endl << GREEN "TEST ADD RANGE" END << std::endl;
	testAddRange();

	return (0);
}

bool	invalidArguments(char* argument)
{
	int size;

	try {
		size = std::atoi(argument);
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

void	testSubject(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	testBase(int size)
{
	Span	span(size);

	if (size > 0)
	{
		std::cout << BLUE "Generating collection of numbers..." END << std::endl;
		for (int i = 0; i < size; i++)
		{
			int	n = std::rand() % 42;
			span.addNumber(n);
			std::cout << n << " ";
		}
	std::cout	<< std::endl << std::endl << CYAN "Span range : " << span << END << std::endl;
	}

	std::cout << BLUE "Trying to overflow range : " END;
	try {
		span.addNumber(std::rand() % 42);
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Exception: "<< e.what() << END;
	}

	std::cout << BLUE "Shortest Span: " END;
	try {
		std::cout << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Exception: "<< e.what() << END << std::endl;
	}

	std::cout << BLUE "Longest Span: " END;
	try {
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Exception: "<< e.what() << END << std::endl;
	}
}

void	testAddRange(void)
{
	Span	span(10);

	std::cout << BLUE "Add range with vector: " END;
	std::vector<int>	vectorRange;
	for (int i = 0; i < 4; i++)
	{
		int n = std::rand() % 42;
		vectorRange.push_back(n);
		std::cout << n << " ";
	}
	span.addRange< std::vector<int> >(vectorRange.begin(), vectorRange.end());
	std::cout << std::endl << CYAN "Span range : " << span << END << std::endl;


	std::cout << BLUE "Add range with list: " END;
	std::list<int>	listRange;
	for (int i = 0; i < 4; i++)
	{
		int n = std::rand() % 42;
		listRange.push_back(n);
		std::cout << n << " ";
	}
	span.addRange< std::list<int> >(listRange.begin(), listRange.end());
	std::cout << std::endl << CYAN "Span range : " << span << END << std::endl;

	std::cout << BLUE "Add range with not enough space in span:" END << std::endl;
	try {
		span.addRange< std::vector<int> >(vectorRange.begin(), vectorRange.end());
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Exception: "<< e.what() << END << std::endl;
	}
	
}