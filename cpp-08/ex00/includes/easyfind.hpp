/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:42:52 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/26 12:03:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

# define BLUE	"\e[34m"
# define CYAN	"\e[96m"
# define YELLOW	"\e[33m"
# define GREEN	"\e[92m"
# define END	"\e[0m"

template <typename T>
void	easyfind(T container, int toFind)
{
	typename T::const_iterator	it;

	std::cout << YELLOW << "Finding " << toFind << "... " << END;
	it = std::find(container.begin(), container.end(), toFind);
	if ( it != container.end())
		std::cout << GREEN << *it << " found in container." << END << std::endl;
	else
		throw std::out_of_range("No occurence of this value.");
}

template <typename T>
void	testValue(T container, int toFind)
{
	try {
		easyfind(container, toFind);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

template <typename T>
void	testContainerType(T& container)
{
	int	n;

	for (int i = 0; i < 10; i++)
	{
		n = rand() % 42;
		container.push_back(n);
		std::cout << CYAN << n << " ";
	}
	std::cout << END << std::endl;
	
	for (int i = 0; i < 5; i++)
		testValue(container, rand() % 42);
}

#endif