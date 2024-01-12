/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:21:22 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/12 11:30:20 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name_;
		bool				isSigned_;
		const	int			requiredSignGrade_;
		const	int			requiredExecGrade_;

	public:
		// Constructors & Destructor
		Form(void);
		Form(const std::string name, const int requiredSignGrade, const int requiredExecGrade);
		Form(const Form& src);
		~Form(void);

		// Overload operator
		Form&	operator=(const Form& src);

		// Public Member functions
		void	beSigned(const Bureaucrat bureaucrat);

		// Accessors
		const std::string	getName(void) const;
		bool				isSigned(void) const;
		int					getRequiredSignGrade() const;
		int					getRequiredExecGrade() const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw ();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw ();
		};
};

std::ostream&	operator<<(std::ostream& oS, const Form& src);

#endif
