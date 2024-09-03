/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:13:09 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/03 20:23:43 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed x)
{
    if (x < 0)
        return (x * -1);
    return (x);
}

static Fixed	area( Point const a, Point const b, Point const c)
{
    return (((a.getX() * (b.getY() - c.getY()))
			+ (b.getX() * (c.getY() - a.getY()))
			+ (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abcArea = abs(area(a, b, c));
	Fixed	pabArea = abs(area(point, a, b));
	Fixed	pbcArea = abs(area(point, b, c));
	Fixed	pcaArea = abs(area(point, c, a));
	return (pabArea.toInt() && pbcArea.toInt() && pcaArea.toInt() && abcArea == (pabArea + pbcArea + pcaArea));
}
