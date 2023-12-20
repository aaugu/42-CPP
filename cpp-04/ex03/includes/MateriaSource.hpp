/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:36:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:40:24 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

class MateriaSource
{
	private:
		/* data */

	public:
		// Constructors & Destructor
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		~MateriaSource(void);

		// Copy assignment
		MateriaSource&	operator=(const MateriaSource& src);
};




#endif
