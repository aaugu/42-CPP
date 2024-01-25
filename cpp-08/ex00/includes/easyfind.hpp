/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:42:52 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/25 14:08:53 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

template <typename T>
void	easyfind(T container, int n)
{
	T<int>::iterator it;

	it = find(container.begin(), container.end(), n);
	if ( it != container.end())
		std::cout << n << " found at position " << *it << std::endl;
	else
		throw NoOccurrenceFound();
}

template <typename T>

class NoOccurrenceFound : public std::exception {
	public:
		virtual const char *	what(void) const throw () {
			return ("No occurence of current value");
		};
};

#endif