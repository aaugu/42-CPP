/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:29:41 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 14:41:52 by aaugu            ###   ########.fr       */
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
	std::string	firstName = _getInput("First Name", ALPHA);
	if (firstName.compare("") == 0)
		return ;

	std::string	lastName = _getInput("Last Name", ALPHA);
	if (lastName.compare("") == 0)
		return ;

	std::string	nickname = _getInput("Nickname", ALPHA);
	if (nickname.compare("") == 0)
		return ;

	std::string	phoneNumber = _getInput("Phone Number", NUM);
	if (phoneNumber.compare("") == 0)
		return ;

	std::string	darkestSecret = _getInput("Darkest secret", 0);
	if (darkestSecret.compare("") == 0)
		return ;

	this->_registerContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
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
		if (std::cin.eof())
		{
			system("clear");
			return ;
		}
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
		if (std::cin.eof())
			return (system("clear"), "");
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

void		PhoneBook::_registerContact(std::string firstName,
										std::string lastName,
										std::string nickname,
										std::string phoneNumber,
										std::string darkestSecret)
{
	this->_index++;
	if (this->_index == 8)
		this->_index = 0;

	if (this->_contacts[this->_index].save(this->_index, firstName, lastName,
		nickname, phoneNumber, darkestSecret))
	{
		if (this->_nbContacts < 8)
			this->_nbContacts++;
		std::cout << "Contact successfully created." << std::endl;	
	}
	else
	{
		this->_index--;
		std::cout << std::endl << ERR_CREATE_CONTACT << std::endl;
	}
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