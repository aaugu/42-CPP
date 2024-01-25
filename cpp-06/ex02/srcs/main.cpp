/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:22:26 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/23 13:45:39 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <typeinfo>
#include <cstdlib>
#include <iostream>
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main(void)
{
	srand(time(NULL));
	Base*	p = NULL;

	for(int i = 0; i < 10; i++)
	{
		p = generate();
		std::cout << " : ";
		identify(p);
		std::cout << " - ";
		identify(*p);
		std::cout << std::endl;
		delete p;
	}
	return (0);
}


/* It randomly instanciates A, B or C and returns the instance as a Base pointer.
Feel free to use anything you like for the random choice implementation. */
Base*	generate(void)
{
	int	randNum = std::rand() % 3;

	switch (randNum)
	{
		case 0:
			std::cout << "Generating A";
			return (new A);
		case 1:
			std::cout << "Generating B";
			return (new B);
		case 2:
			std::cout << "Generating C";
			return (new C);
		default:
			return (NULL);
	}
}

/* It prints the actual type of the object pointed to by p: "A", "B" or "C". */
void	identify(Base* p) {
	if		( dynamic_cast< A* >( p ) )
        std::cout << "A";
    else if ( dynamic_cast< B* >( p ) )
        std::cout << "B";
    else if ( dynamic_cast< C* >( p ) )
        std::cout << "C";
    else if (p == NULL)
        std::cout << "UNKNOWN";
}

/* It prints the actual type of the object pointed to by p: "A", "B" or "C".
Using a pointer inside this function is forbidden. */
void	identify(Base& p) {
	try {
		(void) dynamic_cast< A& >(p);
		std::cout << "A";
		return ;
	}
	catch (std::exception& e) { }
	try {
		(void) dynamic_cast< B& >(p);
		std::cout << "B";
		return ;
	}
	catch (std::exception& e) { }
	try {
		(void) dynamic_cast< C& >(p);
		std::cout << "C";
		return ;
	}
	catch (std::exception& e) { }
	std::cout << "UNKNOWN";
}
