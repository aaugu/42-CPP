/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:53:12 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/12 11:28:22 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

# define ERR_ATTACK_DEAD " cannot attack : he is already dead !"
# define ERR_ATTACK_ENERGY " cannot attack : not enough energy points!"
# define ERR_DAMAGE_DEAD " cannot receive any more damage : he is already dead ! Stop persisting !"
# define ERR_HEAL_ENERGY " cannot heal himself : not enough energy points !"
# define ERR_HEAL_DEAD " cannot heal himself : he is already dead !"

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		// Constructors
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(ClapTrap& clapTrap);

		// Destructor
		~ClapTrap(void);

		// Overloaded operators
		// == Copy assignment ==
		ClapTrap&	operator=(const ClapTrap& rhs);

		// Functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// Accessors
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;

};

#endif // CLAPTRAP_HPP
