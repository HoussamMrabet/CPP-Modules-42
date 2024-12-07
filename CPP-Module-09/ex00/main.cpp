/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:34:24 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 14:02:37 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return (1);
    }

    try
	{
        std::map<std::string, float> db = loadDatabase("data.csv");

        processInput(argv[1], db);
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}
