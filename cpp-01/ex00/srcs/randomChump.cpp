/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:42:02 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 12:49:19 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "../includes/Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	zombie(name);

	zombie.announce();
}
