/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:34:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:39:09 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character
{
	private:
		/* data */

	public:
		// Constructors & Destructor
		Character(void);
		Character(const Character& src);
		~Character(void);

		// Copy assignment
		Character&	operator=(const Character& src);
};

#endif
