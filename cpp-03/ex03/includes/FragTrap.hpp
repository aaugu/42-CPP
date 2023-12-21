/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:24:14 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/14 11:58:04 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "../includes/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		bool	healthBuff;

	public:
		// Constructors
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(FragTrap& fragTrap);

		// Destructor
		~FragTrap(void);

		// Overloaded operators
		// == Copy assignment ==
		FragTrap&	operator=(const FragTrap& rhs);

		// Public function
		void	highFivesGuys(void);
};

#endif
