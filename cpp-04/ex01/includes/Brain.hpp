/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:39:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/20 16:26:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		// Constructors and Destructor
		Brain(void);
		Brain(const Brain& src);
		~Brain(void);

		// Copy assignment
		Brain&	operator=(const Brain& src);

		// Accessors
		std::string	getIdeabyId(int i) const;
		void		setIdeabyId(const std::string idea, int i);

};

#endif
