/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:51:48 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/11 15:14:45 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:
		Contact contacts[8];
		PhoneBook();
		~PhoneBook();
		void	start();
		void	displaycommands();
		void	addContact();
		void	searchContact();
};

#endif