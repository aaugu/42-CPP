/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:24:42 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/08 15:49:47 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"

int main(void)
{
	Fixed	a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "a :                   " << a << std::endl;
	std::cout << "b :                   " << b << std::endl << std::endl;
	std::cout << "Operator + :          " << a + b << std::endl;
	std::cout << "Operator * :          " << a * b << std::endl;
	std::cout << "Operator / :          " << a / b << std::endl;
	std::cout << "Operator / :          " << b / a << std::endl;
	std::cout << "Operator - :          " << a - b << std::endl << std::endl;

	std::cout << "a :                   " << a << std::endl;
	std::cout << "Increment (prefix) :  " << ++a << std::endl;
	std::cout << "a :                   " << a << std::endl;
	std::cout << "Increment (postfix) : " << a++ << std::endl;
	std::cout << "a :                   " << a << std::endl << std::endl;
	
	std::cout << "b :                   " << b << std::endl;
	std::cout << "Min :                 " << Fixed::min( a, b ) << std::endl;
	std::cout << "Max :                 " << Fixed::max( a, b ) << std::endl;

	return (0);
}