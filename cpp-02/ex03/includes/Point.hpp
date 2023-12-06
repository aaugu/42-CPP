/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:21:46 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/24 10:23:36 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "../includes/Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& point);
		~Point(void);

		Point&	operator=(const Point& rhs);

		const Fixed	getX() const;
		const Fixed	getY() const;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif