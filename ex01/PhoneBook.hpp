/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:55:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/10/31 14:30:46 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook
{
private:
	// int	set_first_name(char *first_name);
	// int	set_last_name(char *last_name);
	// int	set_nickname(char *nickname);
	// int	set_phone_number(char *phone_number);
	// int	set_darkest_secret(char *darkest_secret);
public:
	PhoneBook(char *first_name, char *last_name, char *nickname, char *phone_number, char *darkest_secret);
	int	add(char *fn, char *ln, char *nn, char *pn, char *ds);
	int	search();
	int	exit();
	~PhoneBook();
};




#endif