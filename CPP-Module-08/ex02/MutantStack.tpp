/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:06:23 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 00:11:38 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &ms) : std::stack<T>(ms) {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &ms)
{
	if (this != &ms)
		std::stack<T>::operator=(ms);
	return (*this);
}


template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return std::stack<T>::c.end();
}

#endif
