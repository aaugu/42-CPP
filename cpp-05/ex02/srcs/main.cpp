/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:24:04 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/12 16:31:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

// void	instantiateFormTest(void);
// void	createForm(const std::string name, int signGrade, int execGrade);
// void	signTests(void);


int main(void)
{
	// instantiateFormTest();
	// std::cout << "--------------" << std::endl;
	// signTests();
	// return (0);
}

// void	instantiateFormTest(void)
// {
// 	std::cout << BLUE "Instantiate forms :" END << std::endl;
// 	Form	form;
// 	Form	otherForm(form);
// 	Form	other = form;
// 	std::cout	<< CYAN "Base: " END << std::endl << form << std::endl
// 				<< CYAN "Copy constructor: " END << std::endl << otherForm << std::endl
// 				<< CYAN "Copy assignment: " END << std::endl << other << std::endl
// 				<< std::endl;

// 	createForm("Arcanist form", 1, 1);
// 	createForm("Scholar form", 150, 150);
// 	createForm("Summoner form", 33, 33);

// 	std::cout	<< std::endl
// 				<< BLUE "Test instantiate forms with wrong grades :" END
// 				<< std::endl;
// 	createForm("Monk form", 151, 150);
// 	createForm("Ninja form", 1, 0);
// 	createForm("Samourai form", -3, 150);
// }

// void	createForm(const std::string name, int signGrade, int execGrade)
// {
// 	try {
// 		Form	form(name, signGrade, execGrade);
// 		std::cout << form << std::endl;
// 	}
// 	catch (Form::GradeTooHighException& e) {
// 		std::cerr << RED "Exception: " << e.what() << END << std::endl;
// 	}
// 	catch (Form::GradeTooLowException& e) {
// 		std::cerr << RED "Exception: " << e.what() << END << std::endl;
// 	}
// }

// void	signTests(void)
// {
// 	Form	summoner("Summoner form", 1, 1);
// 	Form	reaper("Reaper form", 150, 150);

// 	Bureaucrat	graha("G'raha", 1);
// 	Bureaucrat	zenos("Zenos", 150);

// 	zenos.signForm(summoner);
// 	zenos.signForm(reaper);
// 	std::cout << std::endl;
// 	graha.signForm(reaper);
// 	graha.signForm(summoner);
// 	std::cout << std::endl;
// }
