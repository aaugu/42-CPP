/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:13:08 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 11:03:19 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "../includes/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors & Destructor
		WrongCat(void);
		WrongCat(const WrongCat& src);
		~WrongCat(void);

		// Copy assignment
		WrongCat&	operator=(const WrongCat& src);

		// Public function
		void	makeSound(void) const;
};

#endif
