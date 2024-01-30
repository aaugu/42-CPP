/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:43:40 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/30 10:01:12 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

template < class T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, Container >
{
	public:
		// Canonical Orthodox Form
		MutantStack(void) {};
		MutantStack(const MutantStack& src) { *this = src; };
		~MutantStack(void) {};
		MutantStack&	operator=(const MutantStack& src) {
			if (this != &src)
				this->c = src.c;
			return (*this);
		};

		// Iterators
		typedef typename std::stack<T, Container>::container_type::iterator	iterator;

		MutantStack<T, Container>::iterator	begin(void) { return ( this->c.begin() ); };
		MutantStack<T, Container>::iterator	end(void) { return ( this->c.end() ); };
};

#endif
