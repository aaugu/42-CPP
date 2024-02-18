/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:31:25 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/19 00:19:11 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <exception>
#include <limits>
#include <ctime>
#include <stdlib.h>
#include "../includes/PmergeMe.hpp"

void	checkInput(int nbElements, char** elements);
bool	isPositiveNumber(std::string element);
int*	getNumbersToSort(int nbElements, char** elements);
int		getNumber(std::string element);
bool	isDuplicate(int* numbersToSort, int number, int position);
void	printTimeResult(std::clock_t time, int nbElements, std::string containerType);

int	main(int ac, char** av)
{
	if (ac < 2) {
		std::cout << "Usage: ./PmergeMe <numbers_to_sort>" << std::endl;
		return (1);
	}

	int		nbElements = ac - 1;
	char**	input = av + 1;

	try {
		checkInput(nbElements, input);

		int*	numbersToSort = getNumbersToSort(nbElements, input);
		PmergeMe	pmergeMe(numbersToSort, nbElements);
		delete numbersToSort;

		pmergeMe.printRand("Before:  ", UNSORTED);
		std::clock_t	timeList = pmergeMe.runSorting(LIST);
		std::clock_t	timeVector = pmergeMe.runSorting(VECTOR);
		pmergeMe.printRand("After:   ", SORTED);

		printTimeResult(timeList, nbElements, "list");
		printTimeResult(timeVector, nbElements, "vector");
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

}

// --------------------------- Checks about Input --------------------------- //

void	checkInput(int nbElements, char** elements)
{
	for (int i = 0; i < nbElements; i++)
	{
		if (isPositiveNumber(elements[i]) == false)
			throw std::runtime_error( std::string(elements[i]) + " is not a positive number" );
	}
}

bool	isPositiveNumber(std::string element)
{
	for ( std::string::iterator it = element.begin(); it != element.end(); it++ )
	{
		if (std::isdigit(*it) == false)
			return (false);
	}

	return (true);
}

// ----------- Get number array and while checking for duplicates ----------- //

int*	getNumbersToSort(int nbElements, char** elements)
{
	int*	numbersToSort = new int[nbElements];

	for (int i = 0; i < nbElements; i++)
	{
		numbersToSort[i] = getNumber(elements[i]);
		if (isDuplicate(numbersToSort, numbersToSort[i], i))
			throw std::runtime_error( std::string(elements[i]) + " is a duplicate" );
	}

	return ( numbersToSort );
}

int	getNumber(std::string element)
{
	char* 		endptr;
	long int	num = strtol(element.c_str(), &endptr, 10);


	if (num > std::numeric_limits<int>::max())
		throw std::out_of_range(element + " is too large a number");
	else if (num < 0)
		throw std::out_of_range(element + " is not a positive int");

	return ( static_cast<int>(num) );
}

bool	isDuplicate(int* numbersToSort, int number, int position)
{
	for (int i = 0; i < position; i++)
	{
		if (numbersToSort[i] == number)
			return (true);
	}

	return (false);
}

// --------------------------- Print time result ---------------------------- //

void	printTimeResult(std::clock_t time, int nbElements, std::string containerType)
{
	std::cout	<< std::fixed << std::setprecision(5)
				<< "Time to process a range of " << nbElements
				<< " elements with std::" << containerType << ": "
				<< 1000.0 * time / CLOCKS_PER_SEC << " us" << std::endl;
}
