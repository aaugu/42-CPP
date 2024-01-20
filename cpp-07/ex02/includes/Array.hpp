/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:47:52 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/20 15:03:58 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int	size_;
		T*				array_;

	public:
		// Constructors and Destructor
		Array(void) : size_(0), array_(NULL) {};
		Array(unsigned int size) : size_(size), array_(new T[size]) {};
		Array(const Array& src) : size_(src.size_),array_(new T[src.size_]) {
			for (unsigned int i = 0; i < this->size_; i++)
					this->array_[i] = src.array_[i];
		};
		~Array(void) { delete [] this->array_; };

		// Overload operators
		Array&	operator=(const Array& src) {
			if (this != &src)
			{
				if (this->size_ != src.size())
				{
					delete [] array_;
					this->size_ = src.size();
					this->array_ = new T[this->size_];
				}
				std::cout << "ici\n";
				for (unsigned int i = 0; i < this->size_; i++)
					this->array_[i] = src.array_[i];
			}
			return (*this);
		};

		T&		operator[](unsigned int i) const {
			if (i >= this->size_)
				throw Array::OutOfRangeIndex();
			return (this->array_[i]);
		}

		// Member functions
		unsigned int	size(void) const {
			return (this->size_);
		};

		class OutOfRangeIndex : public std::exception {
			public:
				virtual const char *	what(void) const throw () {
					return ("Index is out of range");
				};
		};
};

template < typename T >
std::ostream&	operator<<(std::ostream& oS, const Array< T >& array) {
	if (array.size() != 0)
	{
		for (unsigned int i = 0; i < array.size(); i++)
			oS << array[i] << " ";
		oS << std::endl;
	}
	return (oS);
}

#endif
