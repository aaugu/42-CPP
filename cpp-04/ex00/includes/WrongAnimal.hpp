/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:13:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 11:16:11 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		// Constructors & Destructor
		WrongAnimal(void);
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal& wrongAnimal);
		~WrongAnimal(void);

		// Copy assignment
		WrongAnimal&	operator=(const WrongAnimal& src);

		// Public member functions
		void makeSound(void) const;

		// Accessors
		const std::string	getType(void) const;
};

#endif
