/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:31:11 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/06 14:10:17 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTOR & DESTRUCTOR                          */
/* ************************************************************************** */

Contact::Contact(void) {
	this->_setFirstName("");
	this->_setLastName("");
	this->_setNickname("");
	this->_setPhoneNumber("");
	this->_setDarkestSecret("");
}

Contact::~Contact(void) {
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	Contact::save(	int id,
						std::string firstName,
						std::string lastName,
						std::string nickname,
						std::string phoneNumber,
						std::string darkestSecret) {
	if (firstName.size() && lastName.size() && nickname.size()
		&& phoneNumber.size() && darkestSecret.size()) {
		this->_setId(id);
		this->_setFirstName(firstName);
		this->_setLastName(lastName);
		this->_setNickname(nickname);
		this->_setPhoneNumber(phoneNumber);
		this->_setDarkestSecret(darkestSecret);
	}
}

void	Contact::displayContactInfos(void) {
	std::cout << "----------------------------" << std::endl;
	std::cout << "|   CONTACT INFORMATIONS   |" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "First name     : " << this->_getFirstName() << std::endl;
	std::cout << "Last name      : " << this->_getLastName() << std::endl;
	std::cout << "Nickname       : " << this->_getNickname() << std::endl;
	std::cout << "Phone Number   : " << this->_getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << this->_getDarkestSecret() << std::endl;
}

void	Contact::displayContactSummary(void) {
	std::cout << "|" << this->_getId() << std::setw(9) << "|";
	this->_printRightAlignedInfo(this->_getFirstName());
	std::cout << "|";
	this->_printRightAlignedInfo(this->_getLastName());
	std::cout << "|";
	this->_printRightAlignedInfo(this->_getNickname());
	std::cout << "|" << std::endl;
}

bool	Contact::isEmpty(void) {
	if (this->_getFirstName().size()
		&& this->_getLastName().size()
		&& this->_getNickname().size()
		&& this->_getPhoneNumber().size() 
		&& this->_getDarkestSecret().size())
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                             PRIVATE FUNCTIONS                              */
/* ************************************************************************** */

void	Contact::_printRightAlignedInfo(std::string info) {
	if (info.size() >= 10)
	{
		info.resize(10);
		info[9] = '.';
		std::cout << info;
	}
	else
		std::cout << std::setw(10 - info.size()) << info;
}

/* ************************************************************************** */
/*                                  SETTERS                                   */
/* ************************************************************************** */

void	Contact::_setId(int id) {
	this->_id = id;
}

void	Contact::_setFirstName(std::string first_name) {
	this->_firstName = first_name;
}

void	Contact::_setLastName(std::string last_name) {
	this->_lastName = last_name;
}

void	Contact::_setNickname(std::string nickname) {
	this->_nickname = nickname;
}

void	Contact::_setPhoneNumber(std::string phone_number) {
	this->_phoneNumber = phone_number;
}

void	Contact::_setDarkestSecret(std::string darkest_secret) {
	this->_darkestSecret = darkest_secret;
}

/* ************************************************************************** */
/*                                  GETTERS                                   */
/* ************************************************************************** */

int	Contact::_getId(void) {
	return (this->_id);
}

std::string	Contact::_getFirstName(void) {
	return (this->_firstName);
}

std::string	Contact::_getLastName(void) {
	return (this->_lastName);
}

std::string	Contact::_getNickname(void) {
	return (this->_nickname);
}

std::string	Contact::_getPhoneNumber(void) {
	return (this->_phoneNumber);
}

std::string	Contact::_getDarkestSecret(void) {
	return (this->_darkestSecret);
}
