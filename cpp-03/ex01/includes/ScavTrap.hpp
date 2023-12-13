/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:17:21 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/12 14:08:31 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "../includes/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_gateGuarding;

	public:
		// Constructors
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(ScavTrap& scavTrap);

		// Destructor
		~ScavTrap(void);

		// Overloaded operators
		// == Copy assignment ==
		ScavTrap&	operator=(const ScavTrap& rhs);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif