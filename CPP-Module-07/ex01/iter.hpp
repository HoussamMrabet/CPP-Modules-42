/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:57:29 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/01 10:04:50 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void	iter(T *arr, size_t len, void (*func)(T&))
{
	size_t i;

	i = 0;
	while (i < len)
	{
		func(arr[i]);
		i++;
	}
}

template <typename T>
void printInt(T &n)
{
    std::cout << n << " ";
}

#endif
