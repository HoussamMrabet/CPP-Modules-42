/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:07:04 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/14 21:54:03 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "An instance has been created!" << std::endl << std::flush;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has been destructed!" << std::endl << std::flush;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl << std::flush;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
