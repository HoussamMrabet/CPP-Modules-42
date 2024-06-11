/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:47:55 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/11 15:32:25 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact
{
	public:
		std::string	index;
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		void	list_contacts();
		void	find_contact(int index);
};

#endif