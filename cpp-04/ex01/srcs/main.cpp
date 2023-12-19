/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:33:18 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 23:43:46 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Animal.hpp"

int main(void)
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << std::endl;
	// delete j; //should not create a leak
	// delete i;
	// std::cout << std::endl << "---------------" << std::endl;

	Dog dog;
	{
		std::cout << std::endl;
		Dog tmpDog = dog;
		std::cout << std::endl;
	}
	std::cout << "---------------" << std::endl;
	// Cat cat;
	// {
	// 	std::cout << std::endl;
	// 	Cat tmpCat = cat;
	// 	std::cout << std::endl;
	// }

	return (0);
}
