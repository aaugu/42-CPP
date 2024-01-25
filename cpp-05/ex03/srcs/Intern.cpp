/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:20:52 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/22 14:32:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Intern::Intern(void) {}

Intern::Intern(const Intern& src) { (void) src; }

Intern::~Intern() {}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

Intern& Intern::operator=(Intern const & src) {
	(void) src;
	return (*this);
}

/* ************************************************************************** */
/*                          PUBLIC MEMBER FUNCTIONS                           */
/* ************************************************************************** */

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	typedef AForm* (Intern::*Forms)(std::string target);

	std::string	formNames[3] = {	"shrubbery creation",
									"robotomy request",
									"presidential pardon"};
	Forms		createForm[3] = {	&Intern::createShrubberyCreationForm_,
									&Intern::createRobotomyRequestForm_,
									&Intern::createPresidentPardonForm_ };

	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(formNames[i]) == 0)
		{
			AForm * form = (this->*createForm[i])(target);
			if (form)
				std::cout << "Intern creates " << *form << std::endl;
			return (form);
		}
	}
	std::cout << "Error: Unknown form type." << std::endl;
	return (NULL);
}

/* ************************************************************************** */
/*                          PRIVATE MEMBER FUNCTIONS                          */
/* ************************************************************************** */

AForm* Intern::createShrubberyCreationForm_(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm_(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentPardonForm_(std::string target) {
	return (new PresidentialPardonForm(target));
}
