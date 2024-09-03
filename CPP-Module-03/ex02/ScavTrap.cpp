/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 05:52:49 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/03 20:23:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->points = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->points = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ct) : ClapTrap(ct.name)
{
	this->points = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ct)
{
	this->name = ct.name;
	this->points = ct.points;
	this->energyPoints = ct.energyPoints;
	this->attackDamage = ct.attackDamage;
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << this->name;
	if (!this->points)
		std::cout << " is already dead!" << std::endl;
	else if (!this->energyPoints)
		std::cout << " has no energy points to attack!" << std::endl;
	else
	{
		std::cout << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	if (!this->points)
		std::cout << " is already dead!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}
