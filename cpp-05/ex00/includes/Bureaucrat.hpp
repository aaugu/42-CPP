/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:16:04 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/10 15:54:07 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	private:
		const std::string	name_;
		int					grade_;

	public:
		// Constructors & Destructor
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);

		// Overload operator
		Bureaucrat&	operator=(const Bureaucrat& src);

		// Public Member functions
		void	incrementGrade(void);
		void	decrementGrade(void);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw ();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw ();
		};

		static const int highestGrade = 1;
		static const int lowestGrade = 150;

		// Accessors
		const std::string	getName(void) const;
		int					getGrade(void) const;
};

std::ostream&	operator<<(std::ostream& oS, const Bureaucrat& src);

#endif
