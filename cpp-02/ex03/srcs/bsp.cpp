/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:13 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/24 12:51:06 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

const Fixed	calculateTriangleArea(const Point a, const Point b, const Point c);
const Fixed getAbsoluteValue(const Fixed value);

/*	Indicates whether a point is inside of a triangle or not in coordinate geometry
*	BSP stands for Binary space partitioning.
*/

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	const Fixed abcArea = calculateTriangleArea(a, b, c);

	const Fixed abpArea = calculateTriangleArea(a, b, point);
	const Fixed acpArea = calculateTriangleArea(a, c, point);
	const Fixed bcpArea = calculateTriangleArea(b, c, point);

	std::cout << abcArea << " " << abpArea << " " << acpArea << " " << bcpArea << std::endl;
 
	if (abpArea == 0 || acpArea == 0 || bcpArea == 0)
		return (std::cout	<< "Point is on the edge or vertex of the triangle." 
							<< std::endl, false);
	return (abcArea == (abpArea + acpArea + bcpArea));
}


/*  The area of triangle in coordinate geometry:
*	The area of a triangle cannot be negative. So we get the absolute value of
*	the formula :
*	(ΔABC) = (1/2) [ x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2) ]
*/
const Fixed	calculateTriangleArea(const Point a, const Point b, const Point c)
{
	return ( getAbsoluteValue (	a.getX() * (b.getY() - c.getY()) +
								b.getX() * (c.getY() - a.getY()) +
								c.getX() * (a.getY() - b.getY()) ).toFloat()
								/ 2);
}

const Fixed getAbsoluteValue(const Fixed value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}