/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:49:27 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/08 15:40:21 by aaugu            ###   ########.fr       */
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

		// Overloaded copy assignment
		Fixed&	operator=(const Fixed& rhs);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

};

std::ostream&	operator<<(std::ostream& oS, const Fixed& rhs);

#endif