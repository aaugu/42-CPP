/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:43:00 by aaugu             #+#    #+#             */
/*   Updated: 2024/01/18 16:53:22 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void	swap(T& a, T& b)
{
    T	tmp;

	tmp = a;
	a = b;
	b = tmp;
	return ;
}

template <typename T> T	min(T& a, T& b)
{
    return (a < b) ? a : b;
}

template <typename T> T	max(T& a, T& b)
{
    return (a > b) ? a : b;
}

#endif
