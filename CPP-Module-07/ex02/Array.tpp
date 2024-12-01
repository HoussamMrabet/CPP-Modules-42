/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:11:23 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/01 10:27:23 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : arr(NULL), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), len(n) {}

template <typename T>
Array<T>::Array(const Array &other) : arr(NULL), len(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] arr;
		len = other.len;
		arr = new T[len];
		for (unsigned int i = 0; i < len; i++)
			arr[i] = other.arr[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= len)
		throw std::out_of_range("Index out of bounds");
	return (arr[index]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= len)
		throw std::out_of_range("Index out of bounds");
	return (arr[index]);
}

template <typename T>
unsigned int	Array<T>::getSize() const
{
	return (len);
}
