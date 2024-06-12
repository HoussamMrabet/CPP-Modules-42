/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:50:03 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/12 19:09:03 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	loud_msg(int ac, char **av)
{
	int	i, j;

	i = 0;
	while (++i < ac && (j = -1))
		while (av[i][++j])
			std::cout << (char)std::toupper(av[i][j]) << std::flush;
	std::cout << std::endl << std::flush;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl << std::flush;
	else
		loud_msg(argc, argv);
}
