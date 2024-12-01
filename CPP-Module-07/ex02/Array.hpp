/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:13:38 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/01 01:19:55 by hmrabet          ###   ########.fr       */
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
		Array() : arr(NULL), len(0) {}

		Array(unsigned int n) : arr(new T[n]()), len(n) {}

		Array(const Array& other) : arr(NULL), len(0)
		{
			*this = other;
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] arr;
				len = other.len;
				arr = new T[len];
				for (unsigned int i = 0; i < len; i++)
					arr[i] = other.arr[i];
			}
			return *this;
		}

		~Array()
		{
			delete[] arr;
		}

		T& operator[](unsigned int index)
		{
			if (index >= len)
				throw std::out_of_range("Index out of bounds");
			return arr[index];
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= len)
				throw std::out_of_range("Index out of bounds");
			return arr[index];
		}

		unsigned int size() const
		{
			return len;
		}
};

#endif
