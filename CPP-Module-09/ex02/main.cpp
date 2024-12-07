/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:52:14 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 15:50:31 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No input provided." << std::endl;
        return (1);
    }

    std::vector<int> inputVector;
    for (int i = 1; i < argc; ++i)
    {
        if (!isPositiveInteger(argv[i]))
        {
            std::cerr << "Error: Invalid input." << std::endl;
            return (1);
        }
        inputVector.push_back(std::atoi(argv[i]));
    }

    std::deque<int> inputDeque(inputVector.begin(), inputVector.end());

    // Display unsorted input
    std::cout << "Before: ";
    displayContainer(inputVector);

    // Sort and time with vector
    clock_t startVector = clock();
    mergeInsertionSort(inputVector);
    clock_t endVector = clock();

    // Sort and time with deque
    clock_t startDeque = clock();
    mergeInsertionSort(inputDeque);
    clock_t endDeque = clock();

    // Display sorted output
    std::cout << "After: ";
    displayContainer(inputVector);

    // Display timings
    double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
    double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector: " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque: " << timeDeque << " us" << std::endl;

    return (0);
}
