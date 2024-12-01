/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:13:38 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/01 10:17:02 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T* arr;
		unsigned int len;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();
		
		Array			&operator=(const Array& other);
		T				&operator[](unsigned int index);
		const T			&operator[](unsigned int index) const;
		unsigned int 	getSize() const;
};

#include "Array.tpp"

#endif
