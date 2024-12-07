/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:00:41 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/01 10:36:42 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
	
    iter(arr, 5, print);
	
    return (0);
}