/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:36:00 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/22 11:21:30 by aaugu            ###   ########.fr       */
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
		AMateria*	materias_[4];

		void	initializeMaterias_(void);
		void	deleteMaterias_(void);

	public:
		// Constructors & Destructor
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		~MateriaSource(void);

		// Copy assignment
		MateriaSource&	operator=(const MateriaSource& src);

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const & type);
};




#endif
