/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:27 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/20 13:48:49 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl << std::flush;
}

Fixed::Fixed(int const fixedPoint) : fixedPoint(fixedPoint << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl << std::flush;
}

Fixed::Fixed(float const fixedPoint) : fixedPoint(std::roundf(fixedPoint * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl << std::flush;
}

Fixed::Fixed(const Fixed &fixed) : fixedPoint(fixed.fixedPoint)
{
	std::cout << "Copy constructor called" << std::endl << std::flush;
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	this->fixedPoint = fixed.fixedPoint;
	std::cout << "Copy assignment operator called" << std::endl << std::flush;
	return (*this);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedPoint) / (1 << fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->fixedPoint >> fractionalBits);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl << std::flush;
}

std::ostream	&operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}
