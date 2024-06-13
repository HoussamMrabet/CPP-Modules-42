/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:18:50 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/13 17:31:12 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie = Zombie("Foo");
	
	zombie.announce();
	zombie.randomChump("hmrabet");
	Zombie	*_zombie = zombie.newZombie("Houbet");
	_zombie->announce();
	delete _zombie;
}