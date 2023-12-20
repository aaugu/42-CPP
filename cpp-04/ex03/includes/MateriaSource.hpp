/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:36:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 18:13:31 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "../includes/AMateria.hpp"
# include "../includes/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	materias[4];

	public:
		// Constructors & Destructor
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		~MateriaSource(void);

		// Copy assignment
		MateriaSource&	operator=(const MateriaSource& src);

		// Methods
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};




#endif
