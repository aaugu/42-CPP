/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:03:04 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/15 16:01:30 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm("Robotomy Request Form",
			RobotomyRequestForm::signGrade,
			RobotomyRequestForm::execGrade),
		target_("Unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	:	AForm("Robotomy Request Form",
			RobotomyRequestForm::signGrade,
			RobotomyRequestForm::execGrade),
		target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	:	AForm(src),
		target_(src.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
	if (this != &src)
		this->target_ = src.getTarget();
	return (*this);
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string	RobotomyRequestForm::getTarget(void) const {
	return (this->target_);
}
