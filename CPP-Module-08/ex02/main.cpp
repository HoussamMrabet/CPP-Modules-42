/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:08:17 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/07 00:22:54 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> stack;

    stack.push(5);
    stack.push(17);

    std::cout << "Top element: " << stack.top() << std::endl;
    stack.pop();
    std::cout << "Stack size: " << stack.size() << std::endl;

    stack.push(3);
    stack.push(5);
    stack.push(737);
    stack.push(0);

    MutantStack<int>::iterator it = stack.begin();
    MutantStack<int>::iterator ite = stack.end();

    std::cout << "Stack contents using iterators:" << std::endl;
    while (it != ite)
	{
        std::cout << *it << std::endl;
        ++it;
    }

    // MutantStack<int>::const_iterator itc = stack.begin();

	// *itc = 5;

	std::cout << "-----------------------------------------" << std::endl;

	std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << "Top element: " << *(--list.end()) << std::endl;
    list.pop_back();
    std::cout << "List size: " << list.size() << std::endl;

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator it1 = list.begin();
    std::list<int>::iterator ite1 = list.end();

    std::cout << "List contents using iterators:" << std::endl;
    while (it1 != ite1)
	{
        std::cout << *it1 << std::endl;
        ++it1;
    }

    return 0;
}