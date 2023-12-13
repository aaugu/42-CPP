/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:25:09 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 14:57:57 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);

	private:
		std::string	_name;

};

Zombie	*zombieHorde(int N, std::string name);

#endif
