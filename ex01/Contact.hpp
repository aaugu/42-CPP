/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:31:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/02 15:38:33 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{	
	public:
		Contact( void );
		~Contact( void );

		void save(Contact contact, int id, std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret );
		void displayContactInfos( Contact contact );
		void displayContactSummary( Contact contact);

	private:
		// int			_id;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		
		// int		setId( int id );
		int		setFirstName( std::string first_name );
		int		setLastName( std::string last_name );
		int		setNickname( std::string nickname );
		int		setPhoneNumber( std::string phone_number );
		int		setDarkestSecret( std::string darkest_secret );
		
		// int		getId( int id );
		std::string	getFirstName( Contact contact );
		std::string	getLastName( Contact contact );
		std::string	getNickname( Contact contact );
		std::string	getPhoneNumber( Contact contact );
		std::string	getDarkestSecret( Contact contact );
};