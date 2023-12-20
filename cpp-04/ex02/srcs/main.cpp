/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:33:18 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:02:41 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/AAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

void	testArray(void);

void	testArray(void);
void	copyCat(void);
void	copyDog(void);

int main(void)
{
	testArray();
	// copyCat();
	// copyDog();

	// Won't compile as Animal is now an abstract class
	// AAnimal*	animal = new AAnimal();
	// animal->makeSound();
	// delete animal;

	return (0);
}

void testArray(void)
{
	std::cout << "Array of animals :" << std::endl;

	AAnimal*	animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << std::endl << "Animals making sounds" << std::endl;
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();

	std::cout << std::endl << "Destroying animals" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];
}


void copyCat(void)
{
	Cat* cat = new Cat();

	std::cout << std::endl << "Setting idea to cat brain : ";
	cat->getBrain()->setIdeabyId("Where is my food ?", 0);
	std::cout << cat->getBrain()->getIdeabyId(0) << std::endl << std::endl;

	std::cout << "Copy Cat :" << std::endl;
	Cat* copyCat = new Cat(*cat);
	std::cout 	<< std::endl
				<< "Copy Cat brain idea : "
				<< copyCat->getBrain()->getIdeabyId(0)
				<< std::endl << std::endl;

	delete cat;
	delete copyCat;
}

void copyDog(void)
{
	Dog* dog = new Dog();

	std::cout << std::endl << "Setting idea to dog brain : ";
	dog->getBrain()->setIdeabyId("I love you buddy !", 0);
	std::cout << dog->getBrain()->getIdeabyId(0) << std::endl << std::endl;

	std::cout << "Copy Dog :" << std::endl;
	Dog* copyDog = new Dog(*dog);
	std::cout 	<< std::endl
				<< "Copy Dog brain idea : "
				<< copyDog->getBrain()->getIdeabyId(0)
				<< std::endl << std::endl;;

	delete dog;
	delete copyDog;
}
