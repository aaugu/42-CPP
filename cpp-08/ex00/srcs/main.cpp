/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:43:57 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/25 14:07:30 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/easyfind.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

int	main(void)
{
	std::vector<int> numbers = {1, 100, 10, 70, 100};

	try {
		easyfind(numbers, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}