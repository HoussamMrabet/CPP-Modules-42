/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:28:14 by hmrabet           #+#    #+#             */
/*   Updated: 2024/08/26 19:53:33 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!av[2][0])
		{
			std::cerr << "You can't replace an empty string!" << std::endl << std::flush;
			return (1);
		}
		Sed	sed(av[1], av[2], av[3]);
		sed.replace();
	}
	else
	{
		std::cerr << "invalid arguments count!" << std::endl << std::flush;
		return (1);
	}
	return (0);
}
