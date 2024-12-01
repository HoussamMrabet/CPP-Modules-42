/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:00:41 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/01 01:04:14 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void printInt(int &n)
{
    std::cout << n << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
	
    iter(arr, 5, printInt);
    
	std::cout << std::endl;
	
    return (0);
}
