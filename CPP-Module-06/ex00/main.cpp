/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:43:52 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/30 04:57:13 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return (1);
    }

    ScalarConverter::convert(argv[1]);
    
	return (0);
}
