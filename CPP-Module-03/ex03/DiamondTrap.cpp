/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 06:38:24 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/22 02:22:59 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->name = name;
    this->points = FragTrap::points;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap Parameterized constructor called" << std::endl << std::flush;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl << std::flush;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl << std::flush;
}
