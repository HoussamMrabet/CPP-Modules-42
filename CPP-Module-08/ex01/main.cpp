/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:29:22 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/06 22:38:40 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span s(3);
		s.addNumber(1);
		try
		{
			s.shortestSpan();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		s.addNumber(2);
		s.addNumber(3);
		s.addNumber(4);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
    try {
        Span sp(5);
		
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }

	try
	{
		Span largeSpan(10000);
        std::vector<int> bigData(10000);
        
		for (int i = 0; i < 10000; ++i)
            bigData[i] = i * 2;

        largeSpan.addNumber(bigData.begin(), bigData.end());

        std::cout << "Shortest Span in largeSpan: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span in largeSpan: " << largeSpan.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    return 0;
}