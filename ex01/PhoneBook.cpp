/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:29:41 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/02 15:53:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
}

int	PhoneBook::displayMenu( void )
{
	std:cout << "----------------------------------------" << std::endl;
	std:cout << "|           PHONE BOOK MENU            |" << std::endl;
	std:cout << "----------------------------------------" << std::endl;
	std:cout << "Please enter 'ADD' or 'SEARCH' or 'EXIT'" << std::endl;
	std:cout << "'ADD' : save a new contact" << std::endl;
	std:cout << "'SEARCH' : display a specific contact" << std::endl;
	std:cout << "'EXIT' : exit phone book" << std::endl;
}

int	PhoneBook::displayContacts()
{
	std:cout << "----------------------------------" << std::endl;
	for(int i = 0; i < getNbContacts(); i++)
	{
		Contact::displayContactSummary(_contacts[i])
		std:cout << "----------------------------------" << std::endl;
	}

}

int	PhoneBook::add()
{
	int			id = getNbContacts();
	std::string	first_name = getInput("First Name");
	std::string	last_name = getInput("Last Name");
	std::string	nickname = getInput("Nickname");
	std::string	phone_number = getInput("Phone Number");
	std::string	darkest_secret = getInput("Darkest secret");
	
	// std:cout << "Please enter 'First Name' : ";
	// std::cin >> first_name;
	// if (!first_name)

	if (id == 8) {
		if (PhoneBook::reorderContacts(_contacts))
			return (1);
		if (Contact::save(_contacts[id], id, first_name, last_name, nickname, phone_number, darkest_secret))
			return (1);
	}
	else {
		if (Contact::save(_contacts[id], id, first_name, last_name, nickname, phone_number, darkest_secret))
			return (1);
	}

	return (0);
}

int	PhoneBook::search()
{
	PhoneBook::displayContacts();
}

int	PhoneBook::exit()
{
}

PhoneBook::~PhoneBook()
{
}
