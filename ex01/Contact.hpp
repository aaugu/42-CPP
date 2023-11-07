/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:31:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/07 11:58:23 by aaugu            ###   ########.fr       */
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
		bool	save(	int id,
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
};

#endif