/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:46:16 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/14 15:20:22 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

int	main(void)
{
	Zombie	firstZombie("Foo");
	firstZombie.announce();

	Zombie *secondZombie = newZombie("Bar");
	secondZombie->announce();

	randomChump("Bob");

	delete	secondZombie;
	return (0);
}
