/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:46 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/16 12:37:55 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

enum literalType { UNKNOWN, CHAR, INT, FLOAT, DOUBLE,  };

class ScalarConverter
{
	private:
		std::string	toChar_;
		int			toInt_;
		float		toFloat_;
		double		toDouble_;
		int			type_;

	public:
		// Constructors and Destructor
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter(void);

		// Overload operator
		ScalarConverter&	operator=(const ScalarConverter& src);

		// Member functions
		void	convert(const std::string& literal);
		// Accessors
};

#endif
