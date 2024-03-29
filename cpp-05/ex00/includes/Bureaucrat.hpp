/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:16:04 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/11 15:07:39 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

# define CYAN "\e[96m"
# define RED  "\e[31m"
# define END  "\e[0m"

class Bureaucrat
{
	private:
		const std::string	name_;
		int					grade_;

	public:
		static const int highestGrade = 1;
		static const int lowestGrade = 150;

		// Constructors & Destructor
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);

		// Overload operator
		Bureaucrat&	operator=(const Bureaucrat& src);

		// Public Member functions
		void	incrementGrade(int i);
		void	decrementGrade(int i);

		// Accessors
		const std::string	getName(void) const;
		int					getGrade(void) const;

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

std::ostream&	operator<<(std::ostream& oS, const Bureaucrat& src);

#endif
