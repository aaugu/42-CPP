/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:44:30 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/30 13:31:47 by aaugu            ###   ########.fr       */
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
	std::cout << GREEN "Mutant Stack :" END << std::endl;
	testMutantStack();
	std::cout << std::endl << std::endl << GREEN "Lists :" END << std::endl;
	testList();

	return (0);
}

void	testMutantStack(void)
{
	MutantStack<int> mstack;

	std::cout << BLUE "Generating collection of integers... " END;
	mstack.push(3);
	mstack.push(14);
	mstack.push(15);
	mstack.push(92);
	mstack.push(65);
	mstack.push(35);

	std::cout	<< "Top of stack : " << mstack.top()
				<< " / Size : " << mstack.size();
	std::cout << BLUE "\nRemoving top of stack... " END;
	mstack.pop();
	std::cout << "Size : " << mstack.size() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << BLUE "Iterating over collection : " END;
	while (it != ite)
	{
		std::cout << CYAN << *it << " " << END;
		++it;
	}

	std::stack<int> s(mstack);
	std::cout << BLUE "\nTop of copy stack : " << CYAN << s.top() << END;
}

void	testList(void)
{
	std::list<int> mstack;

	std::cout << BLUE "Generating collection of integers... " END;
	mstack.push_back(3);
	mstack.push_back(14);
	mstack.push_back(15);
	mstack.push_back(92);
	mstack.push_back(65);
	mstack.push_back(35);

	std::cout << "Size : " << mstack.size() << std::endl;
	std::cout << BLUE "Removing top of stack... " END;
	mstack.pop_back();
	std::cout << "Size : " << mstack.size() << std::endl;

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << BLUE "Iterating over collection : " END;
	while (it != ite)
	{
		std::cout << CYAN << *it << " " << END;
		++it;
	}
}
