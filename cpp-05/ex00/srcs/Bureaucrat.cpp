/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:15:46 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/10 16:18:10 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Bureaucrat.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS & DESTRUCTOR                         */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : name_("No name"), grade_(Bureaucrat::lowestGrade) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name) {

	if (grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	if (grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name_(src.getName()) {
	*this = src;
}

Bureaucrat::~Bureaucrat(void) {}

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                              */
/* ************************************************************************** */

void	Bureaucrat::incrementGrade(void) {
	if (this->grade_ == Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	this->grade_--;
}

void	Bureaucrat::decrementGrade(void) {
	if (this->grade_ == Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	this->grade_++;
}

/* ************************************************************************** */
/*                                 EXCEPTIONS                                 */
/* ************************************************************************** */

const char*	Bureaucrat::GradeTooHighException::what(void) const throw () {
	return ("High grades cannot be below 1");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw () {
	return ("Low grades cannot be above 150");
}

/* ************************************************************************** */
/*                            OVERLOADING OPERATORS                           */
/* ************************************************************************** */

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src)
		this->grade_ = src.getGrade();
	return (*this);
}

std::ostream&	operator<<(std::ostream& oS, const Bureaucrat& src) {
	oS << src.getName() << ", bureaucrat grade "<< src.getGrade() << std::endl;
	return (oS);
}

/* ************************************************************************** */
/*                              GETTERS & SETTERS                             */
/* ************************************************************************** */

const std::string Bureaucrat::getName(void) const {
	return (this->name_);
}

int	Bureaucrat::getGrade(void) const {
	return (this->grade_);
}
