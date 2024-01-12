/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:21:55 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/12 16:11:58 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/AForm.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

AForm::AForm(void) :	name_("Form"),
						isSigned_(false),
						requiredSignGrade_(1),
						requiredExecGrade_(1) {}

AForm::AForm(const std::string name, const int signGrade, const int execGrade)
			: 	name_(name),
				isSigned_(false),
				requiredSignGrade_(signGrade),
				requiredExecGrade_(execGrade) {
	if (signGrade > Bureaucrat::lowestGrade || execGrade > Bureaucrat::lowestGrade)
		throw AForm::GradeTooLowException();
	if (signGrade < Bureaucrat::highestGrade || execGrade < Bureaucrat::highestGrade)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& src) :	name_(src.getName()),
								isSigned_(src.isSigned()),
								requiredSignGrade_(src.getRequiredSignGrade()),
								requiredExecGrade_(src.getRequiredExecGrade()) {}

AForm::~AForm(void) {}

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                              */
/* ************************************************************************** */

void	AForm::beSigned(const Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() > this->requiredSignGrade_)
		throw (AForm::GradeTooLowException());
	if (this->isSigned_ == false)
	{
		this->isSigned_ = true;
		std::cout << *this << " Signed " << *this << std::endl;
	}
	else
		std::cout << this->name_ << " was already signed." << std::endl;
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

AForm&	AForm::operator=(const AForm& src) {
	if (this != &src)
		this->isSigned_ = src.isSigned();
	return (*this);
}

std::ostream&	operator<<(std::ostream& oS, const AForm& src) {
	std::cout	<< src.getName()
				<< ", sign grade " << src.getRequiredSignGrade()
				<< ", execution grade "	<< src.getRequiredExecGrade()
				<< ", signed status is " << src.isSigned();
	return (oS);
}

/* ************************************************************************** */
/*                              GETTERS & SETTERS                             */
/* ************************************************************************** */

const std::string	AForm::getName(void) const {
	return (this->name_);
}

bool	AForm::isSigned(void) const {
	return (this->isSigned_);
}

int	AForm::getRequiredSignGrade() const {
	return (this->requiredSignGrade_);
}

int	AForm::getRequiredExecGrade() const {
	return (this->requiredExecGrade_);
}

/* ************************************************************************** */
/*                                 EXCEPTIONS                                 */
/* ************************************************************************** */

const char*	AForm::GradeTooHighException::what(void) const throw () {
	return ("Grade is too high.");
}

const char*	AForm::GradeTooLowException::what(void) const throw () {
	return ("Grade is too low.");
}
