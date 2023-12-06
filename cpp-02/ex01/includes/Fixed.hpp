/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:49:27 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/20 15:04:01 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		// Constructors
		Fixed(void);
		Fixed(const Fixed& fixed);
		Fixed(const int nb);
		Fixed(const float nb);

		// Destructor
		~Fixed(void);

		// Overloaded copy assignment
		Fixed&	operator=(const Fixed& rhs);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat( void ) const;

	private:
		int					_fixedValue;
		static const int	_nbFractionalBits = 8;

};

std::ostream&	operator<<(std::ostream& oS, const Fixed& rhs);

#endif