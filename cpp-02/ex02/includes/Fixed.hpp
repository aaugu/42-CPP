/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:49:27 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/23 11:41:48 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedValue;
		static const int	_nbFractionalBits = 8;

	public:
		// Constructors
		Fixed(void);
		Fixed(const Fixed& fixed);
		Fixed(const int nb);
		Fixed(const float nb);

		// Destructor
		~Fixed(void);

		// Functions
		int				toInt(void) const;
		float			toFloat( void ) const;
		
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

		// Getters and setters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Overloaded operators
			// Copy assignment
		Fixed&	operator=(const Fixed& rhs);

			// Arithmetic
		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

			// Comparison
		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

			// Incrementation / Decrementation		
		Fixed&	operator++(void); // Prefix
		Fixed&	operator--(void); // Prefix		
		Fixed	operator++(int); // Postfix
		Fixed	operator--(int); // Postfix
};

std::ostream&	operator<<(std::ostream& oS, const Fixed& rhs);

#endif