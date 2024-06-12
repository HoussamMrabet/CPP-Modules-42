/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:54:33 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/12 17:16:23 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

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
	std::cin >> this->contacts[(i % 8) + 1].firstname;
	std::cout << "last name : ";
	std::cin >> this->contacts[(i % 8) + 1].lastname;
	std::cout << "nickname : ";
	std::cin >> this->contacts[(i % 8) + 1].nickname;
	std::cout << "phone number : ";
	std::cin >> this->contacts[(i % 8) + 1].phone_number;
	std::cout << "darkest secret : ";
	std::cin >> this->contacts[(i % 8) + 1].darkest_secret;
	std::cout << "Your contact is saved!" << std::endl << std::endl;
	i++;
}

void	PhoneBook::searchContact()
{
	int	i;

	this->list_contacts();
	std::cout << "Enter a contact index: ";
	std::cin >> i;
	if (i < 1 || i > 8)
		std::cout << "Invalid contact index!" << std::endl;
	else
		this->find_contact(i - 1);
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

	i = 1;
	std::cout << "Contacts list:" << std::endl;
	while (i <= 8)
	{
		if (this->contacts[i].firstname.empty())
			return ;
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << this->ft_print(this->contacts[i].firstname);
		std::cout << "|" << std::setw(10) << this->ft_print(this->contacts[i].lastname);
		std::cout << "|" << std::setw(10) << this->ft_print(this->contacts[i].nickname) << std::endl;
		i++;
	}
}

void	PhoneBook::find_contact(int index)
{
	if (this->contacts[index].firstname.empty())
	{
		std::cout << "this index is still empty!" << std::endl;
		return ;
	}
	std::cout << this->contacts[index].index << std::endl;
	std::cout << this->contacts[index].firstname << std::endl;
	std::cout << this->contacts[index].lastname << std::endl;
	std::cout << this->contacts[index].nickname << std::endl;
	std::cout << this->contacts[index].phone_number << std::endl;
	std::cout << this->contacts[index].darkest_secret << std::endl;
}