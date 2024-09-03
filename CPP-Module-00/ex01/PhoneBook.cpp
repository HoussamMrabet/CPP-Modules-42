/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:54:33 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/03 20:23:22 by hmrabet          ###   ########.fr       */
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
	std::cout << "Welcome to the PhoneBook !" << std::endl;
	this->displaycommands();
}

void	PhoneBook::displaycommands()
{
	std::cout << std::endl << "usage : here is the commands you can use:" << std::endl;
	std::cout << "ADD : save a new contact" << std::endl;
	std::cout << "SEARCH : display a specific contact" << std::endl;
	std::cout << "EXIT : quit the program" << std::endl << std::endl;
	std::cout << "Enter your command: ";
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
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "CYA!" << std::endl;
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
	std::cout << "To add a new contact fill the following informations :" << std::endl;
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
	std::cout << std::endl << "Your contact is saved!" << std::endl << std::endl;
	std::cout << "Enter your command: ";
	i++;
}

bool	PhoneBook::valid_index(std::string input)
{
	for (int j = 0; j < static_cast<int>(input.length()); j++)
	{
		if (!std::isdigit(input[j]))
		{
			std::cout << "Invalid contact index!" << std::endl;
			return (false);
		}
	}
	if (std::stoi(input) < 1 || std::stoi(input) > 8)
	{
		std::cout << "Invalid contact index!" << std::endl;
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
		std::cout << "Enter a contact index: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "CYA!" << std::endl;
			exit(0);
		}
		if (trim(input).empty())
			continue ;
		if (valid_index(input))
			break ;
	}
	if (!this->find_contact(std::stoi(input) - 1))
		std::cout << std::endl << "Enter your command: ";
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
	std::cout << "Contacts list:" << std::endl;
	while (i < 8)
	{
		if (this->contacts[i].get_firstname().empty())
			return ;
		std::cout << "|" << std::setw(10) << (i + 1);
		std::cout << "|" << std::setw(10) << this->ft_print(this->contacts[i].get_firstname());
		std::cout << "|" << std::setw(10) << this->ft_print(this->contacts[i].get_lastname());
		std::cout << "|" << std::setw(10) << this->ft_print(this->contacts[i].get_nickname());
		std::cout << "|" << std::endl;
		i++;
	}
}

bool	PhoneBook::find_contact(int index)
{
	if (this->contacts[index].get_firstname().empty())
	{
		std::cout << "this index is still empty!" << std::endl;
		return (false);
	}
	std::cout << std::endl << this->contacts[index].get_index() << std::endl;
	std::cout << this->contacts[index].get_firstname() << std::endl;
	std::cout << this->contacts[index].get_lastname() << std::endl;
	std::cout << this->contacts[index].get_nickname() << std::endl;
	std::cout << this->contacts[index].get_phone_number() << std::endl;
	std::cout << this->contacts[index].get_darkest_secret() << std::endl;
	std::cout << std::endl << "Enter your command: ";
	return (true);
}