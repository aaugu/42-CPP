/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:54:33 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/14 11:55:54 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "../includes/ScavTrap.hpp"
# include "../includes/FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
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

		// Copy assignment operator
		DiamondTrap&	operator=(const DiamondTrap& rhs);

		using	ScavTrap::attack;
		void	whoAmI(void);
};

#endif
