/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:24:18 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/17 16:31:46 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/StateMachine.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./convert <literal>" << std::endl;
		return (1);
	}
	std::cout << StateMachine::getLiteralTypeFromStateMachine(av[1]) << std::endl;
	return (0);
}
