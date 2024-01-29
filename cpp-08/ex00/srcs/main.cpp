/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:43:57 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/26 12:03:49 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../includes/easyfind.hpp"

void	testArray(void);

int	main(void)
{
	srand(time(NULL));

	std::cout << BLUE "Vector container :" END << std::endl;
	std::vector<int>	vector;
	testContainerType(vector);
	
	std::cout << std::endl << BLUE "List container :" END << std::endl;
	std::list<int>	list;
	testContainerType(list);

	std::cout << std::endl << BLUE "Array container :" END << std::endl;
	testArray();

	return (0);
}

void	testArray(void)
{
	std::array<int, 10>	array;
	int	n;

	for (int i = 0; i < 10; i++)
	{
		n = rand() % 42;
		array.fill(n);
		std::cout << CYAN << n << " ";
	}
	std::cout << END << std::endl;
	
	for (int i = 0; i < 5; i++)
		testValue(array, rand() % 42);
}