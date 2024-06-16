/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:04:43 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/16 16:23:26 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(const std::string& filename, const std::string& s1, const std::string& s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
	std::cout << "A Sed has been created!" << std::endl << std::flush;
}

Sed::~Sed(void)
{
	std::cout << "A Sed has been destructed!" << std::endl << std::flush;
}

void	Sed::replace(void)
{
	std::ifstream input(this->filename);
	if (!input.is_open())
	{
		std::cerr << "Error opening file: " << this->filename << std::endl << std::flush;
		return ;
	}
	std::string content((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));
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
		std::cerr << "Error creating output file: " << outputFilename << std::endl << std::flush;
		return ;
	}
	output << content;
	output.close();
}
