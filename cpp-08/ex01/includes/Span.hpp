/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:43:27 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/30 13:44:30 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

# define RED  	"\e[31m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
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
		Span(const Span& src);
		~Span();

		// Overloading operator
		Span&	operator=(const Span& src);

		// Public member function
		void	addNumber(int num);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		// Template function
		template <typename T>
		void	addRange(typename T::iterator begin, typename T::iterator end)
		{
			if (std::distance(begin, end) > static_cast<int>(_size - _range.size()))
				throw std::range_error("Range too big to be added.");
			else if (std::distance(begin, end) > 0)
				this->_range.insert(this->_range.end(), begin, end);
		}

		// Accessors
		const std::vector<int>	getRange(void) const;

		// Exception
		class NotEnoughArguments : public std::exception {
			public:
				virtual const char *	what(void) const throw ();
		};
};

std::ostream &	operator<<(std::ostream &os, Span &src);

#endif
