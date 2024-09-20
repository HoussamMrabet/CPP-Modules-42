/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:36:59 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 13:02:59 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog), brain(new Brain(*dog.brain))
{
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &dog)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &dog)
	{
		Animal::operator=(dog);
		delete brain;
		brain = new Brain(*dog.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << " sound: barks barks..." << std::endl;
}
