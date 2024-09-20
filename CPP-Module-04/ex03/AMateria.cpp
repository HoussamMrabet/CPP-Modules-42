/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:27:33 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 16:37:01 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria Parametrized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &amateria) : type(amateria.type)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	if (this != &amateria)
		this->type = amateria.type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* Default use of " << this->type << " on " << target.getName() << " *" << std::endl;
}
