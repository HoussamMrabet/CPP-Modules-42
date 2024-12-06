/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:58:57 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/06 22:15:06 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(Span const &s) : maxSize(s.maxSize), numbers(s.numbers) {}

Span::~Span() {}

Span	&Span::operator=(Span const &s)
{
	if (this != &s)
	{
		this->numbers = s.numbers;
		this->maxSize = s.maxSize;
	}

	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->numbers.size() >= this->maxSize)
		throw std::out_of_range("Span is already full");
	this->numbers.push_back(number);
}

int	Span::shortestSpan() const
{
	if (this->numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sortedNumbers = this->numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortestSpan = std::numeric_limits<int>::max();
	size_t	i = 1;
	int tmp;

	while (i < sortedNumbers.size())
	{
		tmp = sortedNumbers[i] - sortedNumbers[i - 1];
		if (tmp < shortestSpan)
			shortestSpan = tmp;
		i++;
	}

	return (shortestSpan);
}

int	Span::longestSpan() const
{
	if (this->numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	int minValue = *std::min_element(this->numbers.begin(), this->numbers.end());
	int maxValue = *std::max_element(this->numbers.begin(), this->numbers.end());

	return (maxValue - minValue);
}
	