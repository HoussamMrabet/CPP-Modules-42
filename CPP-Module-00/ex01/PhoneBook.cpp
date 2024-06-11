/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:54:33 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/11 15:22:09 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
}

void	PhoneBook::addContact()
{
	static int	i;
	std::cout << "To add a new contact fill the following informations :" << std::endl;
	std::cout << "first name : ";
	std::cin >> this->contacts[i % 8].firstname;
	std::cout << "last name : ";
	std::cin >> this->contacts[i % 8].lastname;
	std::cout << "nickname : ";
	std::cin >> this->contacts[i % 8].nickname;
	std::cout << "phone number : ";
	std::cin >> this->contacts[i % 8].phone_number;
	std::cout << "darkest secret : ";
	std::cin >> this->contacts[i % 8].darkest_secret;
	std::cout << "Your contact is saved!" << std::endl << std::endl;
	i++;
}

void	PhoneBook::searchContact()
{
	std::cout << "not done yet" << std::endl;
}

