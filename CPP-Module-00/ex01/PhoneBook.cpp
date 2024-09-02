/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:54:33 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/02 10:28:58 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <string>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::start()
{
	std::cout << "Welcome to the PhoneBook !" << std::endl << std::flush;
	this->displaycommands();
}

void	PhoneBook::displaycommands()
{
	std::cout << std::endl << "usage : here is the commands you can use:" << std::endl << std::flush;
	std::cout << "ADD : save a new contact" << std::endl << std::flush;
	std::cout << "SEARCH : display a specific contact" << std::endl << std::flush;
	std::cout << "EXIT : quit the program" << std::endl << std::endl << std::flush;
	std::cout << "Enter your command: " << std::flush;
}

std::string trim(const std::string& s)
{
    int start = s.find_first_not_of(" \t\n\r\f\v");
    if (start == static_cast<int>(std::string::npos))
        return "";
    int end = s.find_last_not_of(" \t\n\r\f\v");
    return s.substr(start, end - start + 1);
}

std::string	read_input(const std::string msg)
{
	std::string	input;
	
	while (trim(input).empty())
	{
		std::cout << msg << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "CYA!" << std::endl << std::flush;
			exit(0);
		}
	}
	return (input);
}

void	PhoneBook::addContact()
{
	static int	i;
	std::string	input;
	
	this->contacts[(i % 8)].set_index((i % 8) + 1);
	std::cout << "To add a new contact fill the following informations :" << std::endl << std::flush;
	input = read_input("first name : ");
	this->contacts[(i % 8)].set_firstname(input);
	input = read_input("last name : ");
	this->contacts[(i % 8)].set_lastname(input);
	input = read_input("nickname : ");
	this->contacts[(i % 8)].set_nickname(input);
	input = read_input("phone number : ");
	this->contacts[(i % 8)].set_phone_number(input);
	input = read_input("darkest secret : ");
	this->contacts[(i % 8)].set_darkest_secret(input);
	std::cout << std::endl << "Your contact is saved!" << std::endl << std::endl << std::flush;
	std::cout << "Enter your command: " << std::flush;
	i++;
}

bool	PhoneBook::valid_index(std::string input)
{
	for (int j = 0; j < static_cast<int>(input.length()); j++)
	{
		if (!std::isdigit(input[j]))
		{
			std::cout << "Invalid contact index!" << std::endl << std::flush;
			return (false);
		}
	}
	if (std::stoi(input) < 1 || std::stoi(input) > 8)
	{
		std::cout << "Invalid contact index!" << std::endl << std::flush;
		return (false);
	}
	return (true);
}

void	PhoneBook::searchContact()
{
	std::string	input;

	this->list_contacts();
	while (1)
	{
		std::cout << "Enter a contact index: " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "CYA!" << std::endl << std::flush;
			exit(0);
		}
		if (trim(input).empty())
			continue ;
		if (valid_index(input))
			break ;
	}
	if (!this->find_contact(std::stoi(input) - 1))
		std::cout << std::endl << "Enter your command: " << std::flush;
}

std::string	PhoneBook::ft_print(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::list_contacts()
{
	int	i;

	i = 0;
	std::cout << "Contacts list:" << std::endl << std::flush;
	while (i < 8)
	{
		if (this->contacts[i].get_firstname().empty())
			return ;
		std::cout << "|" << std::setw(10) << (i + 1) << std::flush;
		std::cout << "|" << std::setw(10) << this->ft_print(this->contacts[i].get_firstname()) << std::flush;
		std::cout << "|" << std::setw(10) << this->ft_print(this->contacts[i].get_lastname()) << std::flush;
		std::cout << "|" << std::setw(10) << this->ft_print(this->contacts[i].get_nickname()) << std::flush;
		std::cout << "|" << std::endl << std::flush;
		i++;
	}
}

bool	PhoneBook::find_contact(int index)
{
	if (this->contacts[index].get_firstname().empty())
	{
		std::cout << "this index is still empty!" << std::endl << std::flush;
		return (false);
	}
	std::cout << std::endl << this->contacts[index].get_index() << std::endl << std::flush;
	std::cout << this->contacts[index].get_firstname() << std::endl << std::flush;
	std::cout << this->contacts[index].get_lastname() << std::endl << std::flush;
	std::cout << this->contacts[index].get_nickname() << std::endl << std::flush;
	std::cout << this->contacts[index].get_phone_number() << std::endl << std::flush;
	std::cout << this->contacts[index].get_darkest_secret() << std::endl << std::flush;
	std::cout << std::endl << "Enter your command: " << std::flush;
	return (true);
}