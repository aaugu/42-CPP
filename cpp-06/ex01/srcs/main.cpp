/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:55:53 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/23 15:41:26 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.hpp"

int	main(void)
{
	Data	data;
	data.content = "Test";
	data.value = 42;

	std::cout	<< "Data struct -> content: " << data.content
				<< " - value: " << data.value << std::endl;
	std::cout << "Original address :                " << &data << std::endl;

	uintptr_t	serialized = Serializer::serialize(&data);
	Data *		deserialized = Serializer::deserialize(serialized);

	std::cout << "Serialized-Deserialized address : " << deserialized << std::endl;
	std::cout	<< "Data struct -> content: " << deserialized->content
				<< " - value: " << deserialized->value << std::endl;

	return (0);
}
