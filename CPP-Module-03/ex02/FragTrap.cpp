/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 06:24:12 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/21 06:31:29 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->points = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl << std::flush;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->points = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Parameterized constructor called" << std::endl << std::flush;
}

FragTrap::FragTrap(const FragTrap &ct) : ClapTrap(ct.name)
{
	this->points = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Copy constructor called" << std::endl << std::flush;
}

FragTrap	&FragTrap::operator=(const FragTrap &ct)
{
	this->name = ct.name;
	this->points = ct.points;
	this->energyPoints = ct.energyPoints;
	this->attackDamage = ct.attackDamage;
	std::cout << "FragTrap Copy assignment operator called" << std::endl << std::flush;
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << this->name << std::flush;
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << std::flush;
	if (!this->points)
		std::cout << " is already dead!" << std::endl << std::flush;
	else
		std::cout << " sent a positive high fives request!" << std::endl << std::flush;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl << std::flush;
}
