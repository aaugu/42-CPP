/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:59:39 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/11 15:42:04 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"

int	main(void)
{
	ClapTrap	wol("Leenae");
	ClapTrap	zenos("Zenos");

	std::cout << std::endl << "FIRST STRIKE" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		wol.attack("Zenos");		
		zenos.takeDamage(2);
		zenos.beRepaired(1);
		zenos.attack("Leenae");
		wol.takeDamage(0);
		std::cout << std::endl;
	}

	std::cout << std::endl << "FINAL STRIKE" << std::endl;

	zenos.beRepaired(1);
	zenos.beRepaired(1);
	zenos.beRepaired(1);
	zenos.attack("Leenae");
	wol.attack("Zenos");
	zenos.takeDamage(10);
	zenos.beRepaired(1);
	zenos.attack("Leenae");
	zenos.takeDamage(1);

	std::cout << std::endl;

	return (0);
}
