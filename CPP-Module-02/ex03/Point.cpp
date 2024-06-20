/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:31:21 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/20 19:56:49 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(Fixed (0)), y(Fixed (0))
{
}

Point::Point(const float x, const float y) : x(Fixed (x)), y(Fixed (y))
{
}

Point::Point(const Point &point) : x(point.x), y(point.y)
{
}

Point	&Point::operator=(const Point &point)
{
	(Fixed)this->x = point.x;
	(Fixed)this->y = point.y;
    return *this;
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

Point::~Point(void)
{
}
