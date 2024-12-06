/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:54:40 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 00:22:49 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &ms);
		~MutantStack();

		MutantStack<T>	&operator=(MutantStack<T> const &ms);

		typedef	typename std::stack<T>::container_type::iterator		iterator;
		typedef	typename std::stack<T>::container_type::const_iterator	const_iterator;

		iterator				begin();
		const_iterator			begin() const;

		iterator				end();
		const_iterator			end() const;
};

#include "MutantStack.tpp"

#endif
