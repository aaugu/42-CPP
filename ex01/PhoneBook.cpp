/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:29:41 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/06 14:25:34 by aaugu            ###   ########.fr       */
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

int	PhoneBook::addContact()
{
	// int			id = getNbContacts();
	// std::string	first_name = getInput("First Name");
	// std::string	last_name = getInput("Last Name");
	// std::string	nickname = getInput("Nickname");
	// std::string	phone_number = getInput("Phone Number");
	// std::string	darkest_secret = getInput("Darkest secret");

	// std::cout << "Please enter 'First Name' : ";
	// std::cin >> first_name;
	// if (!first_name)

	// if (id == 8) {
	// 	if (PhoneBook::reorderContacts(_contacts))
	// 		return (1);
	// 	if (, id, first_name, last_name, nickname, phone_number, darkest_secret))
	// 		return (1);
	// }
	// else {
	// 	if (Contact::save(_contacts[id], id, first_name, last_name, nickname, phone_number, darkest_secret))
	// 		return (1);
	// }

	return (0);
}

void	PhoneBook::searchContact()
{
	std::string	id;

	if (this->getNbContacts() == 0) {
		std::cout << "No contact registered yet." << std::endl;
		return ;
	}

	this->displayContacts(_contacts);
	std::cout << "Enter the index of the contact you want to display : ";
	std::cin >> id;
	
	if (std::isdigit(id[0]) && id.size() == 1) {
		if (_contacts[id[0] - '0'].isEmpty() == false)
			_contacts[id[0] - '0'].displayContactInfos();
		else {
			std::cout << "No contact registered at this index, try again." << std::endl;
			this->searchContact();
		}
	}
	else {
		std::cout << "Wrong index, should be a digit between 0 and 8." << std::endl;
		this->searchContact();
	}
}

/* ************************************************************************** */
/*                             PRIVATE FUNCTIONS                              */
/* ************************************************************************** */

void	PhoneBook::displayContacts(Contact *_contacts)
{
	if (_contacts) {
		std::cout << "+----------+----------+----------+----------+" << std::endl;
		for(int i = 0; i < this->getNbContacts(); i++)
		{
			_contacts[i].displayContactSummary();
			std::cout << "+----------+----------+----------+----------+" << std::endl;
		}
	}
}



/* ************************************************************************** */
/*                                  SETTERS                                   */
/* ************************************************************************** */

void	PhoneBook::setNbContacts(int nbContacts)
{
	this->_nbContacts = nbContacts;
}

/* ************************************************************************** */
/*                                  GETTERS                                   */
/* ************************************************************************** */

int	PhoneBook::getNbContacts(void)
{
	return (this->_nbContacts);
}

Contact	*PhoneBook::getContacts(void)
{
	return (this->_contacts);
}