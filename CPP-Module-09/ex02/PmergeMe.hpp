/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:48:30 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/08 14:52:08 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>

bool isPositiveInteger(const std::string& str);

template <typename Container>
void displayContainer(const Container& container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}

#include <algorithm>

template <typename Container>
Container generateJacobsthalSequence(size_t size)
{
    Container sequence;
    typename Container::value_type a = 0, b = 1;
    while (sequence.size() < size)
    {
        sequence.push_back(b);
        typename Container::value_type next = a + 2 * b;
        a = b;
        b = next;
    }
    return sequence;
}

template <typename Container>
void mergeInsertionSort(Container& container)
{
    if (container.size() <= 1)
        return;

    typename Container::value_type straggler = 0;
    bool hasStraggler = container.size() % 2 != 0;
    if (hasStraggler)
    {
        straggler = container.back();
        container.pop_back();
    }

    Container pairs;
    for (size_t i = 0; i < container.size(); i += 2)
    {
        if (container[i] > container[i + 1])
            std::swap(container[i], container[i + 1]);
        pairs.push_back(container[i + 1]);
    }

    mergeInsertionSort(pairs);

    Container sorted, pend;
    typename Container::iterator it = pairs.begin();
    for (; it != pairs.end(); ++it)
        sorted.push_back(*it);

    for (size_t i = 0; i < container.size(); i += 2)
        pend.push_back(container[i]);

    Container jacobsthalSequence = generateJacobsthalSequence<Container>(pend.size());

    for (size_t i = 0; i < jacobsthalSequence.size(); ++i)
    {
        size_t idx = jacobsthalSequence[i];
        if (idx <= pend.size())
        {
            typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pend[idx - 1]);
            sorted.insert(pos, pend[idx - 1]);
        }
    }

    if (hasStraggler)
    {
        typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
        sorted.insert(pos, straggler);
    }

    container = sorted;
}

#endif
