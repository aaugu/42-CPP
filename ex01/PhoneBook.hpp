/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:55:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/02 15:21:25 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		void	displayMenu( void );
		int		add( void );
		int		search( void );
		int		exit( void );

	private:
		static int	nbContacts;
		Contact		_contacts[8];

		int	getNbContacts( void )
		int	displayContacts( void );
};

#endif
