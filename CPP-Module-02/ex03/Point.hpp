/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:35:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/20 19:56:53 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		Point	&operator=(const Point &point);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		~Point();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
