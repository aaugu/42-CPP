/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:52 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 14:08:26 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		// Constructors & Destructor
		Ice(void);
		Ice(const Ice& src);
		~Ice(void);

		// Copy assignment
		Ice&	operator=(const Ice& src);

		// Public Member functions
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
