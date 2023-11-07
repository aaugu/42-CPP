/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:19:21 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/07 11:25:58 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

std::string	capitalize(std::string input);

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	system("clear");
	while (true)
	{
		phonebook.displayMenu();
		std::cin >> input;
		system("clear");
		if ((capitalize(input)).compare("EXIT") == 0)
			break ;
		else if ((capitalize(input)).compare("ADD") == 0)
			phonebook.addContact();
		else if ((capitalize(input)).compare("SEARCH") == 0)
			phonebook.searchContact();
		else
			std::cout << input << " : " << "Wrong command." << std::endl;
	}
	std::cout	<< "Phonebook closed. You have successfully lost all of your contacts." 
				<< std::endl;
	return (0);
}

std::string	capitalize(std::string input)
{
	if (input.empty())
		return ("");
	for (int i = 0; i < (int)input.size(); i++)
		input[i] = toupper(input[i]);
	return (input);
}

