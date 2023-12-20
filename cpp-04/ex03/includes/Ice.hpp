/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:52 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:58:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "../includes/AMateria.hpp"
# include "../includes/ICharacter.hpp"

class Ice : public AMateria
{
	private:
		/* data */

	public:
		// Constructors & Destructor
		Ice(void);
		Ice(const Ice& src);
		~Ice(void);

		// Copy assignment
		Ice&	operator=(const Ice& src);

		// Public Member functions
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
