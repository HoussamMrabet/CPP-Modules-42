/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:27:24 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/08 22:36:51 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &cat)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &cat)
		Animal::operator=(cat);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << " sound: meows meows..." << std::endl;
}
