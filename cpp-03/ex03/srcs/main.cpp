/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:59:39 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/14 14:57:39 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	wol("Leenae");
	FragTrap	zenos("Zenos");

	std::cout << std::endl;
	wol.guardGate();
	wol.highFivesGuys();
	wol.whoAmI();
	std::cout << std::endl;

	wol.attack("Zenos");
	zenos.takeDamage(20);

	for (int i = 0; i < 4; i++)
	{
		zenos.attack("Leenae");
		wol.takeDamage(30);
		wol.beRepaired(2);
	}
	std::cout << std::endl;
	
	wol.guardGate();
	wol.highFivesGuys();
	wol.whoAmI();

	std::cout << std::endl;
	return (0);
}
