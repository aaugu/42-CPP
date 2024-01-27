/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:43:27 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/27 14:02:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

# define RED  	"\e[31m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define GREEN	"\e[92m"
# define CYAN	"\e[96m"
# define END	"\e[0m"

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_range;

	public:
		// Constructors and Destructor
		Span(void);
		Span(unsigned int size);
		Span(Span& src);
		~Span();

		// Overloading operator
		Span&	operator=(const Span& src);

		// Public member function
		void	addNumber(unsigned int num);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		// Accessors
		const std::vector<int>	getRange(void) const;
};

std::ostream &	operator<<(std::ostream &os, Span &src);

#endif
