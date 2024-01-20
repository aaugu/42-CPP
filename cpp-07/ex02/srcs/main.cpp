/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:51:31 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/20 15:15:28 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../includes/Array.hpp"

void	testTypeString(void);
void	testTypeInt(void);

int	main(void)
{
	testTypeString();
	testTypeInt();
	return (0);
}

void	testTypeString(void)
{
	std::cout << "Test type string" << std::endl;
	Array<std::string>	original(3);
	original[0] = "Hello";
	original[1] = "42";
	original[2] = "World";
	std::cout << original[0] << original[1] << original[2] << std::endl;

	Array<std::string>	copy1(original);
	Array<std::string>	copy2 = original;
	std::cout	<< "Size: " << original.size() << " - " << original
				<< "Size: " << copy1.size() << " - " << copy1
				<< "Size: " << copy2.size() << " - " << copy2;

	try {
		original[3] = "Wrong";
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		std::cout << original[-2];
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testTypeInt(void)
{
	std::cout << "Test type int" << std::endl;
	Array<int>	original(3);
	original[0] = 1;
	original[1] = 2;
	original[2] = 3;
	std::cout << original[0] << original[1] << original[2] << std::endl;

	Array<int>	copy1(original);
	Array<int>	copy2 = original;
	std::cout	<< "Size: " << original.size() << " - " << original
				<< "Size: " << copy1.size() << " - " << copy1
				<< "Size: " << copy2.size() << " - " << copy2;

	try {
		original[3] = 42;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		std::cout << original[-2];
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
