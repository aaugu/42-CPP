/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:49:50 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 15:03:38 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string&	getType(void) const;
		void				setType(std::string type);

	private:
		std::string	_type;
};

#endif