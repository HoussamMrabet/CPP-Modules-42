/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:56:11 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 14:41:49 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) : type(animal.type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &animal)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

