/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:54:35 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/14 22:07:04 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;
	int		N;
	int		i;

	i = 0;
	std::cout << "How many zombies you want to create: " << std::flush;
	std::cin >> N;
	zombies = zombieHorde(N, "hmrabet");
	while (i < N)
	{
        zombies[i].announce();
		i++;
	}
	delete [] zombies;
	return (0);
}
