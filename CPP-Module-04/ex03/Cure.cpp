/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:45:17 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 14:55:52 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
	std::cout << "Cure Copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &cure)
{
	std::cout << "Cure Copy assignment operator called" << std::endl;
	if (this != &cure)
        AMateria::operator=(cure);
    return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}
