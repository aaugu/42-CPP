/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:34:36 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/18 17:42:36 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "../includes/iter.hpp"

int	main(void)
{
	int even[6] = { 0, 2, 4, 6, 8, 10 };
	::iter(even, 6, printElement);
	std::cout << std::endl;

	float odd[5] = { 1.01f, 3.03f, 5.05f, 7.07f, 9.09f };
	::iter(odd, 5, printElement);
	std::cout << std::endl;

	std::string hello[4] = { "Hello", "World", "of", "42" };
	::iter(hello, 4, printElement);
	std::cout << std::endl;

	char chars[3] = { 'k', 'e', 'k' };
	::iter(chars, 3, printElement);
	std::cout << std::endl;

	return (0);
}
