/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:24:42 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/24 12:55:14 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

int main(void)
{
	const	Point a(0, 0);
	const	Point b(2, 5);
	const	Point c(4, 3);

	const	Point p1(3, 3);
	const	Point p2(-2, -1);
	const	Point p3(0, 0);
	const	Point p4(3, 4);

	std::cout << "In :" << std::endl << bsp(a, b, c, p1) << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "Out :" << std::endl << bsp(a, b, c, p2) << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "Vertex :" << std::endl << bsp(a, b, c, p3) << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "Edge :" << std::endl << bsp(a, b, c, p4) << std::endl;
	return (0);
}