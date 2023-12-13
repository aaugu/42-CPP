/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:54:33 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/13 16:04:35 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "../includes/ScavTrap.hpp"
# include "../includes/FragTrap.hpp"

class DiamondTrap : public ScavTrap
{
	private:
		std::string	_name;

	public:
		// Constructors
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(DiamondTrap& diamondTrap);

		// Destructor
		~DiamondTrap(void);

		// Overloaded operators
		// == Copy assignment ==
		DiamondTrap&	operator=(const DiamondTrap& rhs);
};

#endif
