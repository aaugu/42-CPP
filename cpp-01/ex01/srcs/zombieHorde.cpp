/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:28:19 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 12:51:19 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);

	Zombie	*zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombieHorde[i].setName(name);

	return (zombieHorde);
}
