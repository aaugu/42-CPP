/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:22:32 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/16 09:40:14 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout 	<< "Memory address :" << std::endl
				<< "Of string variable => " << &string << std::endl
				<< "Held by stringPTR  => " << stringPTR << std::endl
				<< "Held by stringREF  => " << &stringREF << std::endl
				<< std::endl;

	std::cout	<< "Value :" << std::endl
				<< "Of string variable      => " << string << std::endl
				<< "Pointed to by stringPRT => " << *stringPTR << std::endl
				<< "Pointed to by stringREF => " << stringREF << std::endl;
	return (0);
}