/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:48:43 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/17 17:56:28 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl << std::flush;
}

Fixed::Fixed(const Fixed &fixed)
{
	this->setRawBits(fixed.getRawBits());
	std::cout << "Copy constructor called" << std::endl << std::flush;
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	this->setRawBits(fixed.getRawBits());
	std::cout << "Copy assignment operator called" << std::endl << std::flush;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl << std::flush;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl << std::flush;
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member function called" << std::endl << std::flush;
	this->fixedPoint = raw;
}
