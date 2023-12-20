/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:07:34 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:13:44 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter
{
	private:
		/* data */
	public:
		// Constructors and Destructor
		ICharacter(void);
		ICharacter(const ICharacter& src);
		~ICharacter(void);

		// Copy assignment overload operator
		ICharacter&	operator=(const ICharacter& src);
};



#endif
