/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:46:25 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 16:13:26 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default constructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		this->learnedAMateria[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		if (materiaSource.learnedAMateria[i])
			this->learnedAMateria[i] = materiaSource.learnedAMateria[i]->clone();
		else
			this->learnedAMateria[i] = NULL;
		i++;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &materiaSource)
	{
		int i = 0;
		while (i < 4)
		{
			delete this->learnedAMateria[i];
			if (materiaSource.learnedAMateria[i])
				this->learnedAMateria[i] = materiaSource.learnedAMateria[i]->clone();
			else
				this->learnedAMateria[i] = NULL;
			i++;
		}
	}
    return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		delete this->learnedAMateria[i];
		i++;
	}
}

void MateriaSource::learnMateria(AMateria *aMateria)
{
	int i = 0;
	while (i < 4)
	{
        if (!learnedAMateria[i]){
            learnedAMateria[i] = aMateria;
            return ;
        }
		i++;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i = 0;
	while (i < 4)
	{
        if (learnedAMateria[i] && learnedAMateria[i]->getType() == type){
            return (learnedAMateria[i]->clone());
        }
		i++;
	}
	return NULL;
}
