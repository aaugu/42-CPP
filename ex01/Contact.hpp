/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:31:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/03 17:56:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void save(	int id,
					std::string firstName,
					std::string lastName,
					std::string nickname,
					std::string phoneNumber,
					std::string darkestSecret);
		void displayContactInfos();
		void displayContactSummary();

	private:
		int			_id;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

		std::string	printInfo(std::string info);

		void	_setId(int id);
		void	_setFirstName(std::string first_name);
		void	_setLastName(std::string last_name);
		void	_setNickname(std::string nickname);
		void	_setPhoneNumber(std::string phone_number);
		void	_setDarkestSecret(std::string darkest_secret);

		int			_getId();
		std::string	_getFirstName();
		std::string	_getLastName();
		std::string	_getNickname();
		std::string	_getPhoneNumber();
		std::string	_getDarkestSecret();
};
