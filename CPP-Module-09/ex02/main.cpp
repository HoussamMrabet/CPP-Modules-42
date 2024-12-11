/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:52:14 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/08 21:06:06 by hmrabet          ###   ########.fr       */
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
        if (!isValidNumber(argv[i]))
        {
            std::cerr << "Error: Invalid input." << std::endl;
            return (1);
        }
        inputVector.push_back(std::atoi(argv[i]));
    }

    std::deque<int> inputDeque(inputVector.begin(), inputVector.end());

    std::cout << "Before: ";
    displayContainer(inputVector);

    clock_t startVector = clock();
    mergeInsertionSort(inputVector);
    clock_t endVector = clock();

    clock_t startDeque = clock();
    mergeInsertionSort(inputDeque);
    clock_t endDeque = clock();

    std::cout << "After: ";
    displayContainer(inputVector);

    double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000;
    double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector: " << std::fixed << std::setprecision(3) << timeVector << " ms" << std::endl;
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque: " << std::fixed << std::setprecision(3) <<timeDeque << " ms" << std::endl;

    return (0);
}
