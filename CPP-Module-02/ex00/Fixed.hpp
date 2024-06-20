/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:48:41 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/17 17:37:17 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					fixedPoint;
	static const int	fractionalBits = 8; 
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed&	operator=(const Fixed &fixed);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	~Fixed();
};

#endif