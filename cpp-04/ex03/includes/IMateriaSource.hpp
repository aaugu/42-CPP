/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:07:44 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:14:05 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

class IMateriaSource
{
	private:
		/* data */
	public:
		// Constructors and Destructor
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource& src);
		~IMateriaSource(void);

		// Copy assignment overload operator
		IMateriaSource&	operator=(const IMateriaSource& src);
};




#endif
