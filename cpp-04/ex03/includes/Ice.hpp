/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:52 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:39:31 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

class Ice
{
	private:
		/* data */

	public:
		// Constructors & Destructor
		Ice(void);
		Ice(const Ice& src);
		~Ice(void);

		// Copy assignment
		Ice&	operator=(const Ice& src);
};

#endif
