/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:48:30 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/08 13:28:06 by hmrabet          ###   ########.fr       */
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
    typename Container::value_type a = 0, b = 1; // Use container's value type
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

    // Step 1: Handle straggler if the size is odd
    typename Container::value_type straggler = typename Container::value_type();
    bool hasStraggler = container.size() % 2 != 0;
    if (hasStraggler)
    {
        straggler = container.back();
        container.pop_back();
    }

    // Step 2: Divide into pairs and sort each pair
    Container pairs;
    for (size_t i = 0; i < container.size(); i += 2)
    {
        if (container[i] > container[i + 1])
            std::swap(container[i], container[i + 1]);
        pairs.push_back(container[i + 1]);
    }

    // Step 3: Sort recursively by the largest elements in pairs
    mergeInsertionSort(pairs);

    // Step 4: Create sorted sequence S and pend array
    Container sorted, pend;
    typename Container::iterator it = pairs.begin();
    for (; it != pairs.end(); ++it)
        sorted.push_back(*it);

    for (size_t i = 0; i < container.size(); i += 2)
        pend.push_back(container[i]);

    // Generate Jacobsthal sequence for pend size
    Container jacobsthalSequence = generateJacobsthalSequence<Container>(pend.size());

    // Step 5: Insert elements from pend into sorted using Jacobsthal order
    for (size_t i = 0; i < jacobsthalSequence.size(); ++i)
    {
        size_t idx = jacobsthalSequence[i];
        if (idx <= pend.size())
        {
            typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pend[idx - 1]);
            sorted.insert(pos, pend[idx - 1]);
        }
    }

    // Step 6: Handle straggler
    if (hasStraggler)
    {
        typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
        sorted.insert(pos, straggler);
    }

    // Replace original container with sorted values
    container = sorted;
}

#endif
