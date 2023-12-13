/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:59:39 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/12 14:33:06 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int	main(void)
{
	ScavTrap	wol("Leenae");
	ScavTrap	zenos("Zenos");
	ClapTrap	tataru("Tataru");

	std::cout << std::endl;
	wol.guardGate();
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		wol.attack("Zenos");		
		zenos.takeDamage(20);
		zenos.beRepaired(1);
		zenos.attack("Leenae");
		wol.takeDamage(0);
		std::cout << std::endl;
	}
	
	tataru.attack("Zenos");
	zenos.takeDamage(0);
	wol.attack("Zenos");	
	zenos.takeDamage(20);
	zenos.beRepaired(1);
	zenos.attack("Leenae");
	wol.attack("Zenos");
	zenos.takeDamage(20);

	std::cout << std::endl;

	return (0);
}
