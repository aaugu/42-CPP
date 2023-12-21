/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:13:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/21 10:35:16 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
	protected:
		std::string	_type;

	public:
		// Constructors & Destructor
		AAnimal(void);
		// AAnimal(const std::string type);
		AAnimal(const AAnimal& src);
		virtual ~AAnimal(void);

		// Copy assignment
		AAnimal&	operator=(const AAnimal& src);

		// Method
		virtual void makeSound(void) const = 0;

		// Accessors
		// const std::string	getType(void) const;
};

#endif
