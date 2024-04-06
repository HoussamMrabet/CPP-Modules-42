/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:50:03 by hmrabet           #+#    #+#             */
/*   Updated: 2024/04/06 07:02:59 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	loud_msg(int ac, char **av)
{
	int	i, j;

	i = 0;
	while (++i < ac && (j = -1))
		while (av[i][++j])
			std::cout << (char)std::toupper(av[i][j]);
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		loud_msg(argc, argv);
}
