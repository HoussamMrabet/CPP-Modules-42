/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:08:12 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 16:11:35 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("")
{
	std::cout << "Character Default constructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		this->inventory[i] = NULL;
		i++;
	}
}

Character::Character(const std::string &name) : name(name)
{
	std::cout << "Character Parametrized constructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		this->inventory[i] = NULL;
		i++;
	}
}

Character::Character(const Character &character) : name(character.name)
{
	std::cout << "Character Copy constructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		if (character.inventory[i])
			this->inventory[i] = character.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
		i++;
	}
}

Character &Character::operator=(const Character &character)
{
	std::cout << "Character Copy assignment operator called" << std::endl;
	if (this != &character)
	{
		int i = 0;
		while (i < 4)
		{
			delete this->inventory[i];
			if (character.inventory[i])
				this->inventory[i] = character.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
			i++;
		}
		this->name = character.name; 
	}
    return (*this);
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		delete this->inventory[i];
		i++;
	}
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	int i = 0;
	while (i < 4)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
		i++;
	}
}

void Character::unequip(int idx)
{
	(idx >= 0 && idx <= 3) && (this->inventory[idx] = NULL);
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && this->inventory[idx])
		this->inventory[idx]->use(target);
}
