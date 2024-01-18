/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:46 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/17 17:20:25 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include "StateMachine.hpp"

class ScalarConverter
{
	private:
		// Orthodox Canonical Form
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter(void);
		ScalarConverter&	operator=(const ScalarConverter& src);

		static std::string	char_;
		static int			int_;
		static float		float_;
		static double		double_;
		static int			type_;

	public:
		// Member functions
		static void	convert(const std::string literal);

		// Exceptions
		class InvalidLiteral : public std::exception {
			public:
				virtual const char *	what(void) const throw ();
		};
};

std::ostream&	operator<<(std::ostream& oS, const ScalarConverter& src);

#endif
