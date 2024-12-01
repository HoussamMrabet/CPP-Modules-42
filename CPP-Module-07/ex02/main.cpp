/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:20:53 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/01 10:25:37 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
	{
        Array<int> intArray(3);
        for (unsigned int i = 0; i < intArray.getSize(); i++)
            intArray[i] = i + 1;

        for (unsigned int i = 0; i < intArray.getSize(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        std::cout << intArray[3] << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
