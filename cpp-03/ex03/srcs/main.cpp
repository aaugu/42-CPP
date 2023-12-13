/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:59:39 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/13 15:49:35 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int	main(void)
{
	ClapTrap	zenos("Zenos");
	ScavTrap	wol("Leenae");
	FragTrap	tataru("Tataru");

	std::cout << std::endl;
	wol.guardGate();
	std::cout << std::endl;

	zenos.attack("Leenae");
	wol.takeDamage(0);
	tataru.attack("Zenos");
	zenos.takeDamage(30);
	std::cout << std::endl;

	wol.attack("Tataru");
	tataru.takeDamage(20);
	tataru.highFivesGuys();
	tataru.beRepaired(20);
	std::cout << std::endl;

	zenos.attack("Leenae");
	zenos.beRepaired(20);
	zenos.takeDamage(20);

	std::cout << std::endl;

	return (0);
}
