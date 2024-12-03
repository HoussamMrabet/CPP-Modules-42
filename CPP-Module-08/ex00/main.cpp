/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:32:41 by hmrabet           #+#    #+#             */
/*   Updated: 2024/12/03 01:57:23 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int	main()
{
	int	ret;

	try
	{
		std::list<int>	lst;

		lst.push_back(5);
		lst.push_back(6);
		lst.push_back(32);
		lst.push_back(15);

		ret = easyfind(lst, 6);
		std::cout << "Value found : " << ret << std::endl;

		ret = easyfind(lst, 33);
		std::cout << "Value found : " << ret << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
        std::vector<int> vec;

		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

        ret = easyfind(vec, 3);
        std::cout << "Value found: " << ret << std::endl;

        ret = easyfind(vec, 10);
        std::cout << "Value found: " << ret << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }
	
	return (0);
}