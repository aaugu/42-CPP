/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:02:48 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/15 16:02:32 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm("Presidential Pardon Form",
			PresidentialPardonForm::signGrade,
			PresidentialPardonForm::execGrade),
		target_("Unknown") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	:	AForm("Presidential Pardon Form",
			PresidentialPardonForm::signGrade,
			PresidentialPardonForm::execGrade),
		target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	:	AForm(src),
		target_(src.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	if (this != &src)
		this->target_ = src.getTarget();
	return (*this);
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string	PresidentialPardonForm::getTarget(void) const {
	return (this->target_);
}