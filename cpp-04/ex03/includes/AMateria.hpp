/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:06:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:13:24 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria
{
	private:
		/* data */
	public:
		// Constructors and Destructor
		AMateria(void);
		AMateria(const AMateria& src);
		~AMateria(void);

		// Copy assignment overload operator
		AMateria&	operator=(const AMateria& src);
};




#endif
