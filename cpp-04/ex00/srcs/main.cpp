/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:33:18 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 11:33:53 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	std::cout << std::endl;
	std::cout << animal->getType() << " : ";
	animal->makeSound();
	std::cout << cat->getType() << " : ";
	cat->makeSound(); //will output the cat sound!
	std::cout << dog->getType() << " : ";
	dog->makeSound();
	std::cout << std::endl;

	delete animal;
	delete cat;
	delete dog;

	std::cout << "-------------------------" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat* trueCat = new WrongCat();

	std::cout << std::endl;
	std::cout << wrongAnimal->getType() << " : ";
	wrongAnimal->makeSound();
	std::cout << wrongCat->getType() << " wrong : ";
	wrongCat->makeSound(); //will output the animal sound!
	std::cout << trueCat->getType() << " true : ";
	trueCat->makeSound(); //will output the cat sound!
	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;
	delete trueCat;

	return (0);
}
