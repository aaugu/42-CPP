/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:46 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/21 16:25:03 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <limits>
# include "StateMachine.hpp"

class ScalarConverter
{
	public:
		// Member functions
		static void	convert(const std::string literal);

		// Exceptions
		class InvalidLiteral : public std::exception {
			public:
				virtual const char *	what(void) const throw ();
		};

	private:
		// Orthodox Canonical Form
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter(void);
		ScalarConverter&	operator=(const ScalarConverter& src);

		static char		_char;
		static int		_int;
		static float	_float;
		static double	_double;
		static bool		_charNotPrintable;
		static bool		_charOverflow;
		static bool		_intOverflow;
		static bool		_floatOverflow;
		static bool		_doubleOverflow;
		static bool		_impossibleFloatDouble;

		static const char		_charMin;
		static const char		_charMax;
		static const int		_intMin;
		static const int		_intMax;
		static const float		_floatMin;
		static const float		_floatMax;
		static const double		_doubleMin;
		static const double		_doubleMax;

		static int	_findType(const std::string literal);

		static void	_convertLiteralToChar(const std::string literal);
		static void	_convertLiteralToInt(const std::string literal);
		static void	_convertLiteralToFloat(const std::string literal);
		static void	_convertLiteralToDouble(const std::string literal);

		static void	_castFromChar(void);
		static void	_castFromInt(void);
		static void	_castFromFloat(void);
		static void	_castFromDouble(void);
		static void	_castFromLiteral(const std::string literal);

		static void	_printConversion(void);
		static void	_printChar(void);
		static void	_printInt(void);
		static void	_printFloat(void);
		static void	_printDouble(void);
};

#endif
