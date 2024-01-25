/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:24:04 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/22 11:55:19 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat	zenos("Zenos", 150);
	Bureaucrat	graha("G'raha", 1);
	std::cout	<< zenos << std::endl
				<< graha << std::endl << std::endl;

	PresidentialPardonForm	presidentialPardonForm("Manager");
	RobotomyRequestForm		robotomyRequestForm	("Dexter");
	ShrubberyCreationForm	shrubberyCreationForm("Tea");
	std::cout	<< presidentialPardonForm << std::endl
				<< robotomyRequestForm << std::endl
				<< shrubberyCreationForm << std::endl;

	std::cout << std::endl << BLUE "Trying to execute non signed forms" END << std::endl;
	zenos.executeForm(presidentialPardonForm);
	zenos.executeForm(robotomyRequestForm);
	zenos.executeForm(shrubberyCreationForm);

	std::cout << std::endl << BLUE "Signing forms" END << std::endl;
	graha.signForm(presidentialPardonForm);
	graha.signForm(robotomyRequestForm);
	graha.signForm(shrubberyCreationForm);

	std::cout << std::endl << BLUE "Trying to execute signed forms" END << std::endl;
	std::cout << CYAN "Fails" END << std::endl;
	zenos.executeForm(presidentialPardonForm);
	zenos.executeForm(robotomyRequestForm);
	zenos.executeForm(shrubberyCreationForm);

	std::cout << std::endl << CYAN "Success" END << std::endl;
	graha.executeForm(presidentialPardonForm);
	graha.executeForm(robotomyRequestForm);
	graha.executeForm(shrubberyCreationForm);

	return (0);
}
