/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:31:11 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/07 13:33:33 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTOR & DESTRUCTOR                          */
/* ************************************************************************** */

Contact::Contact(void)
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::~Contact(void)
{
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

bool	Contact::save(int id, std::string firstName, std::string lastName,
						std::string nickname, std::string phoneNumber,
						std::string darkestSecret)
{
	if (firstName.size() && lastName.size() && nickname.size()
		&& phoneNumber.size() && darkestSecret.size()) {
		this->_id = id;
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_nickname = nickname;
		this->_phoneNumber = phoneNumber;
		this->_darkestSecret = darkestSecret;
		return (true);
	}
	return (false);
}

void	Contact::displayContactInfos(void)
{
	std::cout << "+---------------------------------------+" << std::endl;
	std::cout << "|         CONTACT INFORMATIONS          |" << std::endl;
	std::cout << "+---------------------------------------+" << std::endl;
	std::cout << "First name     : " << this->_firstName << std::endl;
	std::cout << "Last name      : " << this->_lastName << std::endl;
	std::cout << "Nickname       : " << this->_nickname << std::endl;
	std::cout << "Phone Number   : " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret : " << this->_darkestSecret << std::endl;
}

void	Contact::displayContactSummary(void)
{
	std::cout << "|" << std::setw(10);
	std::cout << this->_id << "|";
	this->_printRightAlignedInfo(this->_firstName);
	std::cout << "|";
	this->_printRightAlignedInfo(this->_lastName);
	std::cout << "|";
	this->_printRightAlignedInfo(this->_nickname);
	std::cout << "|" << std::endl;
}

bool	Contact::isEmpty(void)
{
	if (this->_firstName.size()
		&& this->_lastName.size()
		&& this->_nickname.size()
		&& this->_phoneNumber.size() 
		&& this->_darkestSecret.size())
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                             PRIVATE FUNCTIONS                              */
/* ************************************************************************** */

void	Contact::_printRightAlignedInfo(std::string info)
{
	if (info.size() >= 10)
	{
		info.resize(10);
		info[9] = '.';
		std::cout << info;
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << info;
	}
}
