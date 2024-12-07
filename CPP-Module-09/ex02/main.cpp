/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:52:14 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 02:54:01 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

// Function to validate input and convert to integers
bool parseInput(int argc, char** argv, std::vector<int>& sequence) {
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num < 0) {
            std::cerr << "Error: Invalid input detected." << std::endl;
            return false;
        }
        sequence.push_back(num);
    }
    return true;
}

// Merge-Insertion Sort for std::vector
void mergeInsertSort(std::vector<int>& sequence) {
    if (sequence.size() <= 1) return;
    for (size_t i = 1; i < sequence.size(); ++i) {
        int key = sequence[i];
        size_t j = i;
        while (j > 0 && sequence[j - 1] > key) {
            sequence[j] = sequence[j - 1];
            --j;
        }
        sequence[j] = key;
    }
}

// Merge-Insertion Sort for std::deque
void mergeInsertSort(std::deque<int>& sequence) {
    if (sequence.size() <= 1) return;
    for (size_t i = 1; i < sequence.size(); ++i) {
        int key = sequence[i];
        size_t j = i;
        while (j > 0 && sequence[j - 1] > key) {
            sequence[j] = sequence[j - 1];
            --j;
        }
        sequence[j] = key;
    }
}

// Helper function to display the sequence
template <typename Container>
void displaySequence(const Container& sequence) {
    for (typename Container::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Main function
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    std::vector<int> vecSequence;
    if (!parseInput(argc, argv, vecSequence)) {
        return 1;
    }

    // Copy sequence to a deque for separate processing
	std::deque<int> dequeSequence(vecSequence.begin(), vecSequence.end());

    std::cout << "Before: ";
    displaySequence(vecSequence);

    // Sort using std::vector and measure time
    clock_t startVec = clock();
    mergeInsertSort(vecSequence);
    clock_t endVec = clock();

    // Sort using std::deque and measure time
    clock_t startDeque = clock();
    mergeInsertSort(dequeSequence);
    clock_t endDeque = clock();

    std::cout << "After: ";
    displaySequence(vecSequence);

    // Calculate and display times
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << vecSequence.size()
              << " elements with std::vector: " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << dequeSequence.size()
              << " elements with std::deque: " << timeDeque << " us" << std::endl;

    return 0;
}
