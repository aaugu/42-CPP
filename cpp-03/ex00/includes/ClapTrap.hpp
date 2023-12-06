/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:53:12 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/06 15:14:38 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		// Constructors
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(ClapTrap& clapTrap);

		// Overloaded operators
		// == Copy assignment ==
		ClapTrap&	operator=(const ClapTrap& rhs);

		// Destructor
		~ClapTrap(void);

		// Functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);


		// Getters and setters


};

#endif // CLAPTRAP_HPP
