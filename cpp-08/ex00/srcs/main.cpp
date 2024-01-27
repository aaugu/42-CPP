/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:43:57 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/27 13:03:15 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <array>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../includes/easyfind.hpp"

int	main(void)
{
	srand(time(NULL));

	std::cout << BLUE "Vector container :" END << std::endl;
	std::vector<int>	vector;
	testContainerType(vector);

	std::cout << std::endl << BLUE "List container :" END << std::endl;
	std::list<int>	list;
	testContainerType(list);

	// std::cout << std::endl << BLUE "Array container :" END << std::endl;
	// testArray();

	return (0);
}
