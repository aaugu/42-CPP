/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:29:41 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/07 13:32:26 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTOR & DESTRUCTOR                          */
/* ************************************************************************** */

PhoneBook::PhoneBook()
{
	this->_index = -1;
	this->_nbContacts = 0;
}

PhoneBook::~PhoneBook()
{
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	PhoneBook::displayMenu(void)
{
	std::cout << "+---------------------------------------+" << std::endl;
	std::cout << "|            PHONE BOOK MENU            |" << std::endl;
	std::cout << "+---------------------------------------+" << std::endl;
	std::cout << "| 'ADD'    : save a new contact         |" << std::endl;
	std::cout << "| 'SEARCH' : display a specific contact |" << std::endl;
	std::cout << "| 'EXIT'   : exit phone book            |" << std::endl;
	std::cout << "+---------------------------------------+" << std::endl;
	std::cout << "Please enter 'ADD' or 'SEARCH' or 'EXIT' : ";
}

void	PhoneBook::addContact()
{
	std::string	first_name = _getInput("First Name", ALPHA);
	std::string	last_name = _getInput("Last Name", ALPHA);
	std::string	nickname = _getInput("Nickname", ALPHA);
	std::string	phone_number = _getInput("Phone Number", NUM);
	std::string	darkest_secret = _getInput("Darkest secret", 0);

	this->_index++;
	if (this->_index == 8)
		this->_index = 0;

	if (this->_contacts[this->_index].save(this->_index, first_name, last_name,
		nickname, phone_number, darkest_secret))
	{
		if (this->_nbContacts < 8)
			this->_nbContacts++;
		std::cout << "Contact successfully created." << std::endl;	
	}
	else
	{
		this->_index--;
		std::cout << ERR_CREATE_CONTACT << std::endl;
	}
}

void	PhoneBook::searchContact()
{
	std::string	id;

	if (this->_nbContacts == 0) {
		std::cout << ERR_PHONEBOOK_EMPTY << std::endl;
		return ;
	}

	while (true) {
		this->_displayContacts();
		std::cout << "Enter the index of the contact you want to display : ";
		std::cin >> id;
		system("clear");
		if (std::isdigit(id[0]) && id.size() == 1 && id[0] - '0' < 8)
		{
			if (this->_contacts[id[0] - '0'].isEmpty())
				std::cout << ERR_NO_CONTACT << std::endl;
			else
			{
				this->_contacts[id[0] - '0'].displayContactInfos();
				break;
			}
		}
		else
			std::cout << ERR_WRONG_INDEX << std::endl;	
	}
}

/* ************************************************************************** */
/*                             PRIVATE FUNCTIONS                              */
/* ************************************************************************** */

std::string	PhoneBook::_getInput(std::string inputType, int flag)
{
	std::string	input;
	
	while (true)
	{
		std::cout << "Enter " << inputType << " : ";
		std::cin >> input;
		system("clear");
		if (flag == ALPHA)
		{
			if (this->_isInputAlpha(input))
				break;
		}
		else if (flag == NUM)
		{
			if (this->_isPhoneNumberValid(input))
				break ;
		}
		else
			break ;
	}
	return (input);
}

bool	PhoneBook::_isPhoneNumberValid(std::string input)
{
	if (this->_isInputNum(input) == false)
	{
		std::cout << ERR_NOT_ONLY_DIGITS << std::endl;
		return (false);
	}
	if (input.size() < 7 || input.size() > 15)
	{
		std::cout << ERR_WRONG_PHONE_NUMBER << std::endl;
		return (false);
	}
	return (true);
}

bool	PhoneBook::_isInputAlpha(std::string input)
{
	for (int i = 0; i < (int)input.size(); i++)
	{
		if (std::isalpha(input[i]) == false)
		{
			std::cout << ERR_NOT_ALPHA << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	PhoneBook::_isInputNum(std::string input)
{
	for (int i = 0; i < (int)input.size(); i++)
	{
		if (std::isdigit(input[i]) == false)
			return (false);
	}
	return (true);
}

void	PhoneBook::_displayContacts(void)
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for(int i = 0; i < this->_nbContacts; i++)
	{
		this->_contacts[i].displayContactSummary();
		std::cout 	<< "+----------+----------+----------+----------+"
					<< std::endl;
	}
}