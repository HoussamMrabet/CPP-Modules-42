/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:51:48 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/12 17:04:38 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
	public:
		Contact contacts[8];
		PhoneBook();
		~PhoneBook();
		void		start();
		void		displaycommands();
		void		addContact();
		void		searchContact();
		void		list_contacts();
		void		find_contact(int index);
		std::string	ft_print(std::string str);
};

#endif