/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:06:51 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 15:45:53 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Error: Wrong number of arguments" << std::endl, 1);

	Harl 		harl;
	harl.complain(av[1]);

	return (0);
}