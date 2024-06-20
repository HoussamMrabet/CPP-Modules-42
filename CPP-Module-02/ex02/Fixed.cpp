/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:50:30 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/20 16:08:41 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
}

Fixed::Fixed(int const fixedPoint) : fixedPoint(fixedPoint << fractionalBits)
{
}

Fixed::Fixed(float const fixedPoint) : fixedPoint(std::roundf(fixedPoint * (1 << fractionalBits)))
{
}

Fixed::Fixed(const Fixed &fixed) : fixedPoint(fixed.fixedPoint)
{
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	this->fixedPoint = fixed.fixedPoint;
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

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->fixedPoint > fixed.fixedPoint);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->fixedPoint >= fixed.fixedPoint);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->fixedPoint < fixed.fixedPoint);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->fixedPoint <= fixed.fixedPoint);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->fixedPoint == fixed.fixedPoint);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->fixedPoint != fixed.fixedPoint);
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	Fixed	res(this->toFloat() + fixed.toFloat());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	Fixed	res(this->toFloat() - fixed.toFloat());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	Fixed	res(this->toFloat() * fixed.toFloat());
	return (res);
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	Fixed	res(this->toFloat() / fixed.toFloat());
	return (res);
}

Fixed&	Fixed::operator++(void)
{
	this->fixedPoint++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	res;
	res.fixedPoint = this->fixedPoint++;
	return (res);
}

Fixed&	Fixed::operator--(void)
{
	this->fixedPoint--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	res(this->fixedPoint);
	res.fixedPoint = this->fixedPoint--;
	return (res);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed::~Fixed(void)
{
}

std::ostream	&operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}
