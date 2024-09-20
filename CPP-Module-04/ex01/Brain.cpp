/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:54:51 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 12:57:24 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = brain.ideas[i];
		i++;
	}
}

Brain& Brain::operator=(const Brain &brain)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &brain) {
		int i = 0;
		while (i < 100)
		{
			this->ideas[i] = brain.ideas[i];
			i++;
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}
