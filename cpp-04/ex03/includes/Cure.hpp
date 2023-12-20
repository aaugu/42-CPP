/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:43 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 17:39:20 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

class Cure
{
	private:
		/* data */

	public:
		// Constructors & Destructor
		Cure(void);
		Cure(const Cure& src);
		~Cure(void);

		// Copy assignment
		Cure&	operator=(const Cure& src);
};

#endif
