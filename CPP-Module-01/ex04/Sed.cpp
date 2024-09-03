/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:04:43 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/03 20:23:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(const std::string& filename, const std::string& s1, const std::string& s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
	std::cout << "A Sed has been created!" << std::endl;
}

Sed::~Sed(void)
{
	std::cout << "A Sed has been destructed!" << std::endl;
}

void	Sed::replace(void)
{
	std::ifstream	input(this->filename);
	if (!input.is_open())
	{
		std::cerr << "Error opening file: " << this->filename << std::endl;
		return ;
	}
	std::string content;
	char		ch;
	while (input.get(ch))
		content += ch;
	input.close();
	size_t pos = 0;
	while ((pos = content.find(this->s1, pos)) != std::string::npos)
	{
		content.replace(pos, this->s1.length(), this->s2);
		pos += this->s2.length();
	}
	std::string outputFilename = this->filename + ".replace";
	std::ofstream output(outputFilename);
	if (!output.is_open())
	{
		std::cerr << "Error creating output file: " << outputFilename << std::endl;
		return ;
	}
	output << content;
	output.close();
}
