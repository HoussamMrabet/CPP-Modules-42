/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:44:38 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/14 22:09:33 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
    Zombie *zombies;
	int		i;
	
	i = 0;
	zombies = new Zombie[N];
	while (i < N)
	{
        zombies[i].setName(name);
		i++;
	}
    return zombies;
}
