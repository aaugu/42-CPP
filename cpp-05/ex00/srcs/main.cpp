/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:24:04 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/11 12:10:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Bureaucrat.hpp"

void	instantiateBureaucratsTest(void);
void	createBureaucrat(const std::string name, int grade);
void	incrementOrDecrementTest(void);
void	incrementGrade(Bureaucrat& bureaucrat, int i);
void	decrementGrade(Bureaucrat& bureaucrat, int i);

int main(void)
{
	instantiateBureaucratsTest();
	std::cout << "--------------" << std::endl;
	incrementOrDecrementTest();
	return (0);
}

void	instantiateBureaucratsTest(void)
{
	std::cout << CYAN "Instantiate bureaucrats" END << std::endl;
	Bureaucrat	bureaucrat;
	Bureaucrat	me(bureaucrat);
	Bureaucrat	other = bureaucrat;
	std::cout	<< "Base : " << bureaucrat << std::endl
				<< "Copy constructor : " << me << std::endl
				<< "Copy assignment : " << other << std::endl << std::endl;

	createBureaucrat("G'raha", 1);
	createBureaucrat("Alphinaud", 150);
	createBureaucrat("Thancred", 33);

	std::cout	<< std::endl
				<< CYAN "Test instantiate bureaucrats with wrong grades" END
				<< std::endl;
	createBureaucrat("Zenos", 151);
	createBureaucrat("Krile", 0);
	createBureaucrat("Y'sthola", -3);
}

void	incrementOrDecrementTest(void)
{
	Bureaucrat	graha("G'raha", 1);
	Bureaucrat	zenos("Zenos", 150);
	std::cout	<< CYAN "Increment and decrement tests" END << std::endl
				<< graha << std::endl
				<< zenos << std::endl << std::endl;

	incrementGrade(graha, 1);
	decrementGrade(graha, 2);
	std::cout <<  std::endl;
	decrementGrade(zenos, 3);
	incrementGrade(zenos, 4);
}

void	createBureaucrat(const std::string name, int grade)
{
	try {
		Bureaucrat	bureaucrat(name, grade);
		std::cout << bureaucrat << " Successfully hired." << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << RED "Exception: " << e.what() << END << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << RED "Exception: " << e.what() << END << std::endl;
	}
}

void	incrementGrade(Bureaucrat& bureaucrat, int i)
{
	try {
		std::cout << bureaucrat << " Incrementing grade of " << i << "..." << std::endl;
		bureaucrat.incrementGrade(i);
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << RED "Exception: " << e.what() << END << std::endl;
	}
}

void	decrementGrade(Bureaucrat& bureaucrat, int i)
{
	try {
		std::cout << bureaucrat << " Decrementing grade of " << i << "..." << std::endl;
		bureaucrat.decrementGrade(i);
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << RED "Exception: " << e.what() << END << std::endl;
	}
}
