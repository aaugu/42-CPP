/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:25:22 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/14 15:55:43 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name );

int	main(void)
{

	Zombie	*zombies = zombieHorde(3, "Foo");

	if (zombies)
	{
		for (int i = 0; i < 3; i++)
			zombies[i].announce();

		delete [] zombies;
	}

	return (0);
}
