/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:06:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 14:13:47 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type_;

	public:
		// Constructors and Destructor
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria& src);
		virtual ~AMateria(void);

		// Copy assignment overload operator
		AMateria&	operator=(const AMateria& src);

		// Methods
		virtual AMateria*	clone(void) const = 0;
		virtual void 		use(ICharacter& target);

		// Accessors
		const std::string& getType(void) const; //Returns the materia type
};

#endif
