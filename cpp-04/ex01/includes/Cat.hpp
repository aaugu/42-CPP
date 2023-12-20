/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:13:08 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 16:22:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "../includes/Animal.hpp"
# include "../includes/Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		// Constructors & Destructor
		Cat(void);
		Cat(const Cat& src);
		~Cat(void);

		// Copy assignment
		Cat&	operator=(const Cat& src);

		// Public function
		void	makeSound(void) const;

		// Accessor
		Brain*	getBrain();
};

#endif
