/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:37:37 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 12:49:16 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "../includes/Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);

	return (zombie);
}
