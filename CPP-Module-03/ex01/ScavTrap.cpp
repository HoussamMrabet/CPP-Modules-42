/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 05:52:49 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/21 06:17:57 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->points = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl << std::flush;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->points = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Parameterized constructor called" << std::endl << std::flush;
}

ScavTrap::ScavTrap(const ScavTrap &ct) : ClapTrap(ct.name)
{
	this->points = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Copy constructor called" << std::endl << std::flush;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ct)
{
	this->name = ct.name;
	this->points = ct.points;
	this->energyPoints = ct.energyPoints;
	this->attackDamage = ct.attackDamage;
	std::cout << "ClapTrap Copy assignment operator called" << std::endl << std::flush;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << this->name << std::flush;
	if (!this->points)
		std::cout << " is already dead!" << std::endl << std::flush;
	else if (!this->energyPoints)
		std::cout << " has no energy points to attack!" << std::endl << std::flush;
	else
	{
		std::cout << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl << std::flush;
		this->energyPoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl << std::flush;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl << std::flush;
}
