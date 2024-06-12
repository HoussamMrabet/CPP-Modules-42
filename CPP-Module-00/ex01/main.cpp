/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:46 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/12 18:56:10 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

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
	PhoneBook book;
	book.start();
	while (1)
	{
		std::string	input;
		std::cin >> input;
		ft_toupper(input);
		if (input == "EXIT")
		{
			std::cout << "cya!" << std::endl;
			break ;
		}
		else if (input == "ADD")
			book.addContact();
		else if (input == "SEARCH")
			book.searchContact();
		else
		{
			std::cout << "Enter a valid command !" << std::endl;
			book.displaycommands();
		}
	}
	return (0);
}