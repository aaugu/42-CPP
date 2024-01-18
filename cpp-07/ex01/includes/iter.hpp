/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:55:03 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/18 17:42:05 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstdio>

/*
Implement a function template iter that takes 3 parameters and returns nothing.
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be call on every element of the array.
*/
template <typename T> void	iter(T* array, size_t size, void (*function)(const T&))
{
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

template <typename T> void	printElement(const T& element)
{
	std::cout << element << " ";
}

#endif
