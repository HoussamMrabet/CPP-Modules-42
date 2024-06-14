/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:12:19 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/14 23:01:31 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;
	
	std::cout << "The memory address of the string variable : " << &brain << std::endl << std::flush;
	std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl << std::flush;
	std::cout << "The memory address held by stringREF : " << &stringREF << std::endl << std::flush;
	std::cout << "The value of the string variable : " << brain << std::endl << std::flush;
	std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl << std::flush;
	std::cout << "The value pointed to by stringREF : " << stringREF << std::endl << std::flush;
}
