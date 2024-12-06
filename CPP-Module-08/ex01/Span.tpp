/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:56:19 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/06 22:26:06 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
# define SPAN_TPP

template <typename It>
void Span::addNumber(It begin, It end)
{
	unsigned int rangeSize = std::distance(begin, end);

	if (rangeSize > this->maxSize - this->numbers.size())
		throw std::out_of_range("Not enough space to add all numbers in range");

	this->numbers.insert(this->numbers.end(), begin, end);
}

#endif
