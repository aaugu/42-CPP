/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:46 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/17 16:08:19 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include "StateMachine.hpp"

class ScalarConverter
{
	private:
		// Constructors and Destructor
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter(void);

		std::string	char_;
		std::string	int_;
		std::string	float_;
		std::string	double_;
		int			type_;

	public:
		// Overload operator
		ScalarConverter&	operator=(const ScalarConverter& src);

		// Member functions
		static void	convert(const std::string& literal);

		// Accessors

};

std::ostream&	operator<<(std::ostream& oS, const ScalarConverter& src);

#endif
