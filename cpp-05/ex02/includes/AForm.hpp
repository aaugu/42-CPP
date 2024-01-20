/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:21:22 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/20 15:26:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name_;
		bool				isSigned_;
		const	int			requiredSignGrade_;
		const	int			requiredExecGrade_;

	protected:
		virtual void	beExecuted(void) const = 0;

	public:
		// Constructors & Destructor
		AForm(void);
		AForm(const std::string name, const int requiredSignGrade, const int requiredExecGrade);
		AForm(const AForm& src);
		virtual ~AForm(void);

		// Overload operator
		AForm&	operator=(const AForm& src);

		// Public Member functions
		void	beSigned(const Bureaucrat bureaucrat);
		void	execute(const Bureaucrat& executor) const;

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

std::ostream&	operator<<(std::ostream& oS, const AForm& src);

#endif
