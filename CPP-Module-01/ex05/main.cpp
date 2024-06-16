/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:30:00 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/16 17:07:21 by hmrabet          ###   ########.fr       */
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

int	main(void)
{
	while (1)
	{
		Harl		harl;
		std::string	input;
		
		std::cout << "Enter a level: " << std::flush;
		std::cin >> input;
		ft_toupper(input);
		if (input == "EXIT")
			break ;
		harl.complain(input);
	}
	return (0);	
}
