/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:54:35 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/02 10:55:37 by hmrabet          ###   ########.fr       */
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
	if (N < 0)
	{
		std::cout << "You must enter a positif number!" << std::endl << std::flush;
		return (0);
	}
	zombies = zombieHorde(N, "hmrabet");
	while (i < N)
	{
        zombies[i].announce();
		i++;
	}
	delete [] zombies;
	return (0);
}
