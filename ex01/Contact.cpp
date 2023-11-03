/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:31:11 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/02 15:53:36 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact( void )
{
	setFirstName( NULL );
	setLastName( NULL );
	setNickname( NULL );
	setPhoneNumber( NULL );
	setDarkestSecret( NULL );
}

void Contact::save( Contact int id, std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret )
{
	// setId( id );
	setFirstName( firstName );
	setLastName( lastName );
	setNickname( nickname );
	setPhoneNumber( phoneNumber );
	setDarkestSecret( darkestSecret );
}

void	Contact::display( Contact contact)
{
	std:cout << "------------------------" << std::endl;
	std:cout << "| CONTACT INFORMATIONS |" << std::endl;
	std:cout << "------------------------" << std::endl;
	// std:cout << "Id             : " << getId(contact) << std::endl;
	std:cout << "First name     : " << getFirstName(contact) << std::endl;
	std:cout << "Last name      : " << getLastName(contact) << std::endl;
	std:cout << "Nickname       : " << getNickname(contact) << std::endl;
	std:cout << "Phone Number   : " << getPhoneNumber(contact) << std::endl;
	std:cout << "Darkest Secret : " << getDarkestSecret(contact) << std::endl;
}

Contact::~Contact( void )
{
}