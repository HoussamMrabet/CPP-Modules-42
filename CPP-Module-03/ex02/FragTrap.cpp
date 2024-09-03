/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 06:24:12 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/03 20:23:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->points = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->points = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ct) : ClapTrap(ct.name)
{
	this->points = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &ct)
{
	this->name = ct.name;
	this->points = ct.points;
	this->energyPoints = ct.energyPoints;
	this->attackDamage = ct.attackDamage;
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << this->name;
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name;
	if (!this->points)
		std::cout << " is already dead!" << std::endl;
	else
		std::cout << " sent a positive high fives request!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}
