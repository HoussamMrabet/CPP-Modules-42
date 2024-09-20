/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:56:40 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 16:12:36 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	std::cout << "Ice Copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &ice)
{
	std::cout << "Ice Copy assignment operator called" << std::endl;
	if (this != &ice)
        AMateria::operator=(ice);
    return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}
