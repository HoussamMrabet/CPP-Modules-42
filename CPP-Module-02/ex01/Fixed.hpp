/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:23 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/20 14:57:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixedPoint;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int fixedPoint);
		Fixed(const float fixedPoint);
		Fixed(const Fixed &fixed);
		Fixed&	operator=(const Fixed &fixed);
		float	toFloat(void) const;
		int		toInt(void) const;
		~Fixed();
};

std::ostream&	operator<<(std::ostream &output, const Fixed &fixed);

#endif
