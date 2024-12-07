/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:48:30 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 15:52:43 by hmrabet          ###   ########.fr       */
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

bool isPositiveInteger(const std::string& str);

template <typename Container>
void displayContainer(const Container& container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}

template <typename Container>
void mergeInsertionSort(Container& container)
{
    if (container.size() <= 1)
        return;

    // Step 1: Handle straggler if the size is odd
    typename Container::value_type straggler = 0;
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
    for (size_t i = 0; i < pairs.size(); ++i)
        sorted.push_back(pairs[i]);
    for (size_t i = 0; i < container.size(); i += 2)
        pend.push_back(container[i]);

    // Step 5: Insert elements from pend into sorted
    for (typename Container::iterator it = pend.begin(); it != pend.end(); ++it)
    {
        typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), *it);
        sorted.insert(pos, *it);
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
