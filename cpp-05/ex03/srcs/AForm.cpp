/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:21:55 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/20 15:26:02 by aaugu            ###   ########.fr       */
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
	if (this->isSigned_ == false)
	{
		if (bureaucrat.getGrade() > this->requiredSignGrade_)
			throw (AForm::GradeTooLowException());
		this->isSigned_ = true;
		std::cout << bureaucrat << " signed " << *this << std::endl;
	}
	else
		std::cout << this->name_ << " was already signed." << std::endl;
}

void	AForm::execute(const Bureaucrat& bureaucrat) const {
	if (this->isSigned_ == true)
	{
		if (bureaucrat.getGrade() > this->requiredSignGrade_)
			throw (AForm::GradeTooLowException());
		this->beExecuted();
	}
	else
		std::cout << this->name_ << " should be signed before executed." << std::endl;
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
