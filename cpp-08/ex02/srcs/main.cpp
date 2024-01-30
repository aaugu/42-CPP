/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:44:30 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/30 09:56:06 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <cstdlib>
#include "../includes/MutantStack.hpp"

# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define GREEN	"\e[92m"
# define CYAN	"\e[96m"
# define END	"\e[0m"

void	testMutantStack(void);
void	testList(void);

int	main(void)
{
	srand(time(NULL));
	// testMutantStack();
	testList();

	return (0);
}

void	testMutantStack(void)
{
	MutantStack<int> mstack;

	std::cout << BLUE "Generating collection of integers:" END << std::endl;
	for (int i = 0; i < 5; i++)
	{
		int n = rand() % 42;
		mstack.push(n);
		std::cout << n << " ";
	}

	std::cout	<< "\n\nTop of stack : " << mstack.top()
				<< " / Size : " << mstack.size() << std::endl;
	std::cout << PURPLE "\nRemoving top of stack..." END << std::endl;
	mstack.pop();
	std::cout << "Size : " << mstack.size() << std::endl;

	std::cout << PURPLE "\nAdding elements..." END << std::endl;
	for (int i = 0; i < 5; i++)
	{
		int n = rand() % 42;
		mstack.push(n);
		std::cout << n << " ";
	}

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	(void) ite;
	std::cout << "\nIterating over collection" << std::endl;
	while (it != ite)
	{
		std::cout << CYAN << *it << " " << END;
		++it;
	}

	std::stack<int> s(mstack);
}

void	testList(void)
{
	std::list<int> mstack;

	std::cout << BLUE "Generating collection of integers:" END << std::endl;
	for (int i = 0; i < 6; i++)
	{
		int n = rand() % 100;
		mstack.push_back(n);
		std::cout << CYAN << n << " " << END;
	}

	std::cout << " / Size : " << mstack.size() << std::endl;
	std::cout << PURPLE "\nRemoving top of stack..." END << std::endl;
	mstack.pop_back();
	std::cout << "Size : " << mstack.size() << std::endl;

	std::cout << PURPLE "\nAdding elements..." END << std::endl;
	for (int i = 0; i < 7; i++)
	{
		int n = rand() % 42;
		mstack.push_back(n);
	}

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "Iterating over collection" << std::endl;
	while (it != ite)
	{
		std::cout << CYAN << *it << " " << END;
		++it;
	}
}
