/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:03:04 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/22 11:57:37 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
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
/*                              MEMBER FUNCTIONS                              */
/* ************************************************************************** */

void	RobotomyRequestForm::beExecuted(void) const {
	std::cout << "*rizzz... bzzzzzz...* ";
	if (std::rand() % 2)
		std::cout << this->target_ << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Oh no! " << this->target_ << "robotomy failed" << std::endl;
}

/* ************************************************************************** */
/*                                  ACCESSORS                                 */
/* ************************************************************************** */

const std::string	RobotomyRequestForm::getTarget(void) const {
	return (this->target_);
}
