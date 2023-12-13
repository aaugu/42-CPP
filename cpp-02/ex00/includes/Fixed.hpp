/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:27:05 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/08 14:36:28 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_fixedValue;
		static const int	_nbFractionalBits = 8;

	public:
		// Default constructor
		Fixed(void);

		// Copy constructor
		Fixed(const Fixed& fixed);

		// Destructor
		~Fixed(void);

		// Overloaded copy assignment
		Fixed& operator= (const Fixed& fixed);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif