/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:03:27 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/22 11:59:22 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include <errno.h>
#include "../includes/ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm("Shrubbery Creation Form",
			ShrubberyCreationForm::signGrade,
			ShrubberyCreationForm::execGrade),
		target_("Unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	:	AForm("Shrubbery Creation Form",
			ShrubberyCreationForm::signGrade,
			ShrubberyCreationForm::execGrade),
		target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	:	AForm(src),
		target_(src.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	if (this != &src)
		this->target_ = src.getTarget();
	return (*this);
}

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                              */
/* ************************************************************************** */

void	ShrubberyCreationForm::beExecuted(void) const {
	std::ofstream	oFS;
	std::string		base = this->target_;
	std::string		outFile = base.append("_shrubbery");

	oFS.open(outFile.c_str(), std::ofstream::out | std::ofstream::app);
	if (oFS.good())
	{
		oFS << ShrubberyCreationForm::teaTree;
		std::cout	<< "A " << this->target_ << " shrubbery has been planted at "
					<< outFile << std::endl;
		oFS.close();
	}
	else {
		std::cout << "Error:" << outFile << ": " << strerror(errno) << std::endl;
	}
}

const std::string ShrubberyCreationForm::teaTree =
"	        |_|_|\n"
"       _|||;;_/\n"
"       ||%||%:b/\n"
"       ~|dO%|i::b/\n"
"  ._H||dSf|||%::H_.\n"
"  ._H@|dLF|}|;::H_.\n"
"._H||dXFt||;.:H_.\n"
"._?|{|P|||/;:.P_.\n"
" ._Hy||t|||;:H_.\n"
"   ._?|x||T|;i:P_.\n"
"    ._H||i||;:H_.\n"
"    ._H|'|||;:H_.\n"
" .=================.\n"
" |;;|#H#|;;;;;;;;: |\n"
" .=================.\n"
"  |;|#H#|;;;;;;;: |\n"
"   |;|#H#|;;;;;: |\n"
"   |;|#H#|;;;;;: |\n"
"    |;|#H#|;;;: |\n"
"    |;|#H#|;;;: |\n"
"     |;|#H#|;: |\n"
"      =========\n\n";

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string	ShrubberyCreationForm::getTarget(void) const {
	return (this->target_);
}
