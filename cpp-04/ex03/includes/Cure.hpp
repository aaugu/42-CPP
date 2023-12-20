/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:43 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:58:22 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "../includes/AMateria.hpp"
# include "../includes/ICharacter.hpp"

class Cure : public AMateria
{
	private:
		/* data */

	public:
		// Constructors & Destructor
		Cure(void);
		Cure(const Cure& src);
		~Cure(void);

		// Copy assignment
		Cure&	operator=(const Cure& src);

		// Public Member functions
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
