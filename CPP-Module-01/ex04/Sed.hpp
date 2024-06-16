/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:58:57 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/16 16:22:40 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;

	public:
		Sed(const std::string& filename, const std::string& s1, const std::string& s2);
		void replace(void);
		~Sed(void);
};

#endif
