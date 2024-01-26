/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:43:27 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/26 14:20:18 by aaugu            ###   ########.fr       */
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
		std::vector<unsigned int>	_vector;
		int							_N;

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
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		// Accessors
		std::vector<unsigned int>	getVector();
};

#endif