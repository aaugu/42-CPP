/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:55:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/06 14:24:25 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		// Functions
		void	displayMenu(void);
		int		addContact(void);
		void	searchContact(void);

	private:
		// Variables
		int			_nbContacts;
		Contact		_contacts[8];
		
		// Functions
		// std::string	getInput(std::string inputType);
		void		displayContacts(Contact *_contacts);

		// Setters
		void		setNbContacts(int nbContacts);
		
		// Getters
		int			getNbContacts(void);
		Contact		*getContacts(void);
		
		
};

#endif
