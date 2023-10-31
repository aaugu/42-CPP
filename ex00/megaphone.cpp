/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:31:10 by aaugu             #+#    #+#             */
/*   Updated: 2023/10/31 13:45:14 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

int	main(int ac, char **av)
{
	if (ac == 1)
		return ((std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl), 0);
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; j < (int)strlen(av[i]); j++)
			std::cout << (char)toupper(av[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
