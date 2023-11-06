/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:31:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/06 14:10:52 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		// Functions
		void	save(	int id,
						std::string firstName,
						std::string lastName,
						std::string nickname,
						std::string phoneNumber,
						std::string darkestSecret);
		void	displayContactInfos(void);
		void	displayContactSummary(void);
		bool	isEmpty(void);

	private:
		// Variables
		int			_id;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

		// Functions
		void	_printRightAlignedInfo(std::string info);

		// Setters
		void	_setId(int id);
		void	_setFirstName(std::string first_name);
		void	_setLastName(std::string last_name);
		void	_setNickname(std::string nickname);
		void	_setPhoneNumber(std::string phone_number);
		void	_setDarkestSecret(std::string darkest_secret);

		// Getters
		int			_getId();
		std::string	_getFirstName();
		std::string	_getLastName();
		std::string	_getNickname();
		std::string	_getPhoneNumber();
		std::string	_getDarkestSecret();
};

#endif