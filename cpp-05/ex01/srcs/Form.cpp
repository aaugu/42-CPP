/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:21:55 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/12 15:47:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Form.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Form::Form(void) : 	name_("Form"),
					isSigned_(false),
					requiredSignGrade_(1),
					requiredExecGrade_(1) {}

Form::Form(const std::string name, const int signGrade, const int execGrade)
			: 	name_(name),
				isSigned_(false),
				requiredSignGrade_(signGrade),
				requiredExecGrade_(execGrade) {
	if (signGrade > Bureaucrat::lowestGrade || execGrade > Bureaucrat::lowestGrade)
		throw Form::GradeTooLowException();
	if (signGrade < Bureaucrat::highestGrade || execGrade < Bureaucrat::highestGrade)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& src) :	name_(src.getName()),
								isSigned_(src.isSigned()),
								requiredSignGrade_(src.getRequiredSignGrade()),
								requiredExecGrade_(src.getRequiredExecGrade()) {}

Form::~Form(void) {}

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                              */
/* ************************************************************************** */

void	Form::beSigned(const Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() > this->requiredSignGrade_)
		throw (Form::GradeTooLowException());
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

Form&	Form::operator=(const Form& src) {
	if (this != &src)
		this->isSigned_ = src.isSigned();
	return (*this);
}

std::ostream&	operator<<(std::ostream& oS, const Form& src) {
	std::cout	<< src.getName()
				<< ", sign grade " << src.getRequiredSignGrade()
				<< ", execution grade "	<< src.getRequiredExecGrade()
				<< ", signed status is " << src.isSigned();
	return (oS);
}

/* ************************************************************************** */
/*                              GETTERS & SETTERS                             */
/* ************************************************************************** */

const std::string	Form::getName(void) const {
	return (this->name_);
}

bool	Form::isSigned(void) const {
	return (this->isSigned_);
}

int	Form::getRequiredSignGrade() const {
	return (this->requiredSignGrade_);
}

int	Form::getRequiredExecGrade() const {
	return (this->requiredExecGrade_);
}

/* ************************************************************************** */
/*                                 EXCEPTIONS                                 */
/* ************************************************************************** */

const char*	Form::GradeTooHighException::what(void) const throw () {
	return ("Grade is too high.");
}

const char*	Form::GradeTooLowException::what(void) const throw () {
	return ("Grade is too low.");
}
