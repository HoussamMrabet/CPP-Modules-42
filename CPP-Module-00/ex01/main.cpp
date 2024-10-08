/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:46 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/03 20:23:22 by hmrabet          ###   ########.fr       */
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
		std::getline(std::cin, input);
		ft_toupper(input);
		if (input == "EXIT" || std::cin.eof())
		{
			std::cout << "CYA!" << std::endl;
			break ;
		}
		else if (input == "ADD")
			book.addContact();
		else if (input == "SEARCH")
			book.searchContact();
		else
		{
			std::cout << std::endl << "Enter a valid command !" << std::endl;
			book.displaycommands();
		}
	}
	return (0);
}