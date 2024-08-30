/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:51:48 by hmrabet           #+#    #+#             */
/*   Updated: 2024/08/30 17:12:39 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void		start();
		void		displaycommands();
		void		addContact();
		void		searchContact();
		void		list_contacts();
		bool		find_contact(int index);
		bool		valid_index(std::string input);
		std::string	ft_print(std::string str);
};

#endif