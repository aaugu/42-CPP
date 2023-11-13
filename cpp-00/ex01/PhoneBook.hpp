/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:55:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/07 13:18:06 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

// Error messages
# define ERR_PHONEBOOK_EMPTY "Phone book empty : no contact registered yet."
# define ERR_WRONG_INDEX "Wrong index, should be a digit between 0 and 8."
# define ERR_NO_CONTACT "No contact registered at this index, try again."
# define ERR_WRONG_PHONE_NUMBER "A valid phone number contains between 7 and 15 digits."
# define ERR_NOT_ONLY_DIGITS "A valid phone number can contain only digits."
# define ERR_NOT_ALPHA "Should contain only alphabetical letters."
# define ERR_CREATE_CONTACT "Problem while creating contact."

// Flags
# define ALPHA 1
# define NUM 2

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		// Functions
		void	displayMenu(void);
		void	addContact(void);
		void	searchContact(void);

	private:
		// Variables
		int		_index;
		int		_nbContacts;
		Contact	_contacts[8];
		
		// Functions
		std::string	_getInput(std::string inputType, int flag);
		bool		_isInputAlpha(std::string input);
		bool		_isPhoneNumberValid(std::string input);
		bool		_isInputNum(std::string input);
		void		_displayContacts(void);
};

#endif
