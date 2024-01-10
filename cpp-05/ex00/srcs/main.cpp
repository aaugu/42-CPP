/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:24:04 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/10 16:17:55 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Bureaucrat.hpp"

void	instantiateWrongGrades(void);
void	incrementOrDecrementWrongGrades(void);

int main(void)
{
	instantiateWrongGrades();
	std::cout << "--------------" << std::endl;
	incrementOrDecrementWrongGrades();
	return (0);
}

void	instantiateWrongGrades(void)
{
	try {
		Bureaucrat	zenos("Zenos", 158);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	krile("Krile", 0);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	incrementOrDecrementWrongGrades(void)
{
	Bureaucrat	graha("G'raha", 1);
	Bureaucrat	zenos("Zenos", 150);
	std::cout << graha << zenos << std::endl;

	std::cout << "Increment G'raha :" << std::endl;
	try {
		graha.incrementGrade();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Decrement G'raha :" << std::endl;
	graha.decrementGrade();
	std::cout << graha << std::endl;

	std::cout << "Decrement Zenos :" << std::endl;
	try {
		zenos.decrementGrade();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Increment Zenos :" << std::endl;
	zenos.incrementGrade();
	std::cout << zenos;
}
