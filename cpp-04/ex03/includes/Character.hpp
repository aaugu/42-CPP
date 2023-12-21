/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:34:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 16:57:51 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	name_;
		AMateria*	materias_[4];

		void	initializeMaterias_(void);
		void	deleteMaterias_(void);

	public:
		// Constructors & Destructor
		Character(void);
		Character(const std::string name);
		Character(const Character& src);
		~Character(void);

		// Copy assignment
		Character&	operator=(const Character& src);

		// Public Member functions
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		// Accessors
		const std::string&	getName(void) const;
};

#endif
