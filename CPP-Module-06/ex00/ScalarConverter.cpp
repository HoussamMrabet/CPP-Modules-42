/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:51:08 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/30 09:08:50 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static void		caster(const std::string &literal)
{
	double	n = atof(literal.c_str());

	if (n < -std::numeric_limits<double>::max() || n > std::numeric_limits<double>::max())
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	
	std::cout << "int: ";
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;
	
	std::cout << "float: ";
	if (n > std::numeric_limits<float>::max() || n < -std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(1) << n << std::endl;
}

void ScalarConverter::convert(const std::string	&literal)
{
	try
	{
		if (literal.length() == 0)
		{
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: 0" << std::endl;
			std::cout << "float: 0.0f" << std::endl;
			std::cout << "double: 0.0" << std::endl;
			return ;
		}
		if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
		{
			if (static_cast<unsigned char>(literal[0]) > 127)
				std::cout << "char: impossible" << std::endl;
			else if (literal[0] != 9 && literal[0] < 32)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << literal[0] << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << std::endl;
			return ;
		}
		if (literal == "nan" || literal == "nanf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
		}
		if (literal == "+inff" || literal == "+inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: +inf" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			return ;
		}
		if (literal == "-inff" || literal == "-inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: -inf" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			return ;
		}
		if (literal[literal.length() - 1] == 'f')
		{
			std::size_t	i = 0;
			int			dots = 0;

			if (literal[i] == '-' || literal[i] == '+')
				i++;
			while (i < literal.length() - 1 && ((literal[i] >= '0' && literal[i] <= '9') || literal[i] == '.'))
			{
				if (literal[i] == '.')
					dots++;
				i++;
			}
			if (dots > 1)
				throw "nan";
			if (i == literal.length() - 1)
			{
				caster(literal);
				return ;
			}
		}
		if (literal.find('.') != std::string::npos)
		{
			std::size_t	i = 0;
			int			dots = 0;
			
			if (literal[i] == '-' || literal[i] == '+')
				i++;
			while ((literal[i] >= '0' && literal[i] <= '9') || literal[i] == '.')
			{
				if (literal[i] == '.')
					dots++;
				i++;
			}
			if (dots > 1)
				throw "nan";
			if (i == literal.length())
			{
				caster(literal);
				return ;
			}
		}
		if ((literal[0] >= '0' && literal[0] <= '9') || literal[0] == '-' || literal[0] == '+')
		{
			std::size_t	i = 0;

			if (literal[i] == '-' || literal[i] == '+')
				i++;
			while ((literal[i] >= '0' && literal[i] <= '9'))
				i++;
			if (i == literal.length())
			{
				caster(literal);
				return;
			}
		}
		throw "nan";
	}
	catch (const char *e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: nan" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}