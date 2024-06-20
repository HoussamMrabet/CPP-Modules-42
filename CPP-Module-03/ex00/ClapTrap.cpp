/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:09:26 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/20 20:49:30 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name(""), points(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl << std::flush;
}

ClapTrap::ClapTrap(std::string name) : name(name), points(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Parameterized constructor called" << std::endl << std::flush;
}

ClapTrap::ClapTrap(const ClapTrap &ct) : name(ct.name), points(ct.points), energyPoints(ct.energyPoints), attackDamage(ct.attackDamage)
{
	std::cout << "Copy constructor called" << std::endl << std::flush;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ct)
{
	this->name = ct.name;
	this->points = ct.points;
	this->energyPoints = ct.energyPoints;
	this->attackDamage = ct.attackDamage;
	std::cout << "Copy assignment operator called" << std::endl << std::flush;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->name << std::flush;
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

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << std::flush;
	if (!this->points)
		std::cout << " is already dead!" << std::endl << std::flush;
	else if (this->points <= amount)
	{
		std::cout << " took " << this->points << " points of damage!" << std::endl << std::flush;
		std::cout << "ClapTrap " << this->name << " has been slain!" << std::endl << std::flush;
		this->points = 0;
	}
	else
	{
		std::cout << " took " << this->points << " points of damage!" << std::endl << std::flush;
		this->points -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << std::flush;
	if (!this->points)
		std::cout << " is already dead!" << std::endl << std::flush;
	else if (!this->energyPoints)
		std::cout << " has no energy points to attack!" << std::endl << std::flush;
	else
	{
		this->energyPoints--;
		std::cout << " repairs itself and gets " << amount << " hit points back!" << std::endl << std::flush;
		points += amount;
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl << std::flush;
}
