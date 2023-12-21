/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:43 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 14:08:08 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		// Constructors & Destructor
		Cure(void);
		Cure(const Cure& src);
		~Cure(void);

		// Copy assignment
		Cure&	operator=(const Cure& src);

		// Public Member functions
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
