/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:13:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/19 11:02:47 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		// Constructors & Destructor
		Animal(void);
		Animal(const std::string type);
		Animal(const Animal& src);
		virtual ~Animal(void);

		// Copy assignment
		Animal&	operator=(const Animal& src);

		// Method
		virtual void makeSound(void) const;

		// Accessors
		const std::string	getType(void) const;
};

#endif
