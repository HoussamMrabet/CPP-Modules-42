/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:14:37 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/16 17:31:03 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	ft_toupper(std::string& input)
{
	int	i;
	
	i = 0;
	while (input[i])
	{
		input[i] = std::toupper(input[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl		harl;
		std::string	level;

		level = av[1];
		ft_toupper(level);
		harl.complain(level);
	}
	else
		std::cerr << "invalid arguments count!" << std::endl << std::flush;
	return (0);	
}
