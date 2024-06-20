/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:58:05 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/20 20:04:48 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point a(0, 0);
	Point b(5, 5);
	Point c(10, 0);
	Point point(3, 3);

	if (bsp(a, b, c, point))
		std::cout << "Point is in the triangle" << std::endl << std::flush;
	else
		std::cout << "Point is not in the triangle" << std::endl << std::flush;
	return 0;
}
