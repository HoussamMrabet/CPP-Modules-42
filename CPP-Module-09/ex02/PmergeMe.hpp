/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:48:30 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/08 21:12:20 by hmrabet          ###   ########.fr       */
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
#include <limits>

bool isValidNumber(const std::string& str);

template <typename Container>
void displayContainer(const Container& container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}

template <typename Container>
Container generateJacobsthalSequence(size_t size)
{
    Container sequence;

    sequence.push_back(0);
    sequence.push_back(1);
    sequence.push_back(1);
    for (size_t i = 2 ; i < size + 2 ; i++)
        sequence.push_back(sequence[i] + (2 * sequence[i - 1]));
    
    Container saveSeq;
    saveSeq.push_back(0);
    saveSeq.push_back(1);
    saveSeq.push_back(1);
    size_t h  = 1;
    for (size_t i = 3 ; i < sequence.size(); i++)
    {
        saveSeq.push_back(sequence[i]);
        size_t depre = saveSeq.back() - 1;
        while (depre > h){
            saveSeq.push_back(depre);
            depre--;
        }
        if (h > size){
            break;
        }
        h = sequence[i];
    }
    saveSeq.erase(saveSeq.begin(), saveSeq.begin() + 3);
    return (saveSeq);
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

    for (size_t i = 0; i < container.size(); i += 2)
    {
        if (container[i] < container[i + 1])
            std::swap(container[i], container[i + 1]);
    }
    

    for (size_t i = 0; i < container.size(); i += 2)
    {
        for (size_t j = i + 2; j < container.size(); j += 2)
        {
            if (container[i] > container[j])
            {
                std::swap(container[i], container[j]);
                std::swap(container[i + 1], container[j + 1]);
            }
        }
    }

    Container sorted, pend;
    for (size_t i = 0; i < container.size(); i += 2)
        sorted.push_back(container[i]);

    for (size_t i = 1; i < container.size(); i += 2)
        pend.push_back(container[i]);

    Container jacobsthalSequence = generateJacobsthalSequence<Container>(pend.size());

    size_t verifyInsert = 0;
    for (size_t i = 0 ; i < jacobsthalSequence.size(); i++)
    {
        if (verifyInsert >= pend.size())
            break;
        if (static_cast<size_t>(jacobsthalSequence[i] - 2) >= pend.size())
            continue;
        size_t element = pend[(jacobsthalSequence[i] - 2)];
        sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), element), element);
        verifyInsert++;
    }

    if (hasStraggler)
    {
        typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
        sorted.insert(pos, straggler);
    }

    container = sorted;
}

#endif
