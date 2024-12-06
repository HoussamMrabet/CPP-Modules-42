/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:42:18 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 00:23:30 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span
{
	private:
		unsigned int maxSize;
		std::vector<int> numbers;
		
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &s);
		~Span();
		Span	&operator=(Span const &s);

		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;

		template <typename It>
		void	addNumber(It begin, It end);
};

#include "Span.tpp"


#endif