/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:19:21 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 14:42:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

bool	emptyInput();

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	std::system("clear");
	while (true)
	{
		if (emptyInput())
			return (0);
		phonebook.displayMenu();
		std::cin >> input;
		std::system("clear");
		if (emptyInput())
			return (0);
		if (input.compare("EXIT") == 0)
			break ;
		else if (input.compare("ADD") == 0)
			phonebook.addContact();
		else if (input.compare("SEARCH") == 0)
			phonebook.searchContact();
		else
			std::cout << input << " : " << "Wrong command." << std::endl;
	}
	std::cout << MSG_CLOSE_PHONEBOOK << std::endl;
	return (0);
}

bool	emptyInput()
{
	if (std::cin.eof())
		return (std::cout << MSG_CLOSE_PHONEBOOK << std::endl, true);
	return (false);
}