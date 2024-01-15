/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:03:27 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/15 16:03:17 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string	ShrubberyCreationForm::getTarget(void) const {
	return (this->target_);
}
