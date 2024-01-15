/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:24:04 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/15 18:48:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
	Intern	base;
	Intern	test(base);
	Intern	intern = test;

	AForm*	rrf = intern.makeForm("robotomy request", "Dexter");
	AForm*	scf = intern.makeForm("shrubbery creation", "Tea tree");
	AForm*	ppf = intern.makeForm("presidential pardon", "Manager");
	AForm*	uf = intern.makeForm("unknown", "unknown");
	AForm*	ef = intern.makeForm("", "");

	delete (rrf);
	delete (scf);
	delete (ppf);

	return (0);
}
