/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:46:16 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 12:48:15 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

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
