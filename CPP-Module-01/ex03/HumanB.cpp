/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:08:21 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/03 20:23:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
	std::cout << "A HumanB has been created!" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->name << " has been destructed!" << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with";
	if (this->weapon)
		std::cout << " their " << this->weapon->getType() << std::endl;
	else
		std::cout << "out weapons" << std::endl;
}
