/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:12:36 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 16:22:24 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "../includes/Animal.hpp"
# include "../includes/Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		// Constructors & Destructor
		Dog(void);
		Dog(const Dog& src);
		~Dog(void);

		// Copy assignment
		Dog&	operator=(const Dog& src);

		// Public function
		void	makeSound(void) const;

		// Accessor
		Brain*	getBrain();
};

#endif
