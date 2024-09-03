/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:23:03 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/03 20:23:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "A Weapon has been created!" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << this->type << " has been destructed!" << std::endl;
}

const std::string	Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(const std::string type)
{
	this->type = type;
}
