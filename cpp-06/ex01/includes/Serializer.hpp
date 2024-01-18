/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:41:02 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/18 15:07:31 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h>

struct Data
{
	std::string		content;
	int				value;
};

class Serializer
{
	private:
		// Orthodox Canonical Form
		Serializer(void);
		Serializer(const Serializer& src);
		~Serializer(void);
		Serializer&	operator=(const Serializer& src);

	public:
		// Member functions
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
