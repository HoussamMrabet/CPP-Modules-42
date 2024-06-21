/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:09:35 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/21 06:40:42 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap houbet("houbet");
	
	houbet.attack("hmrabet");
	houbet.takeDamage(80);
	houbet.beRepaired(20);
	houbet.attack("hmrabet");
	houbet.takeDamage(40);
	houbet.beRepaired(20);
	houbet.attack("hmrabet");
	
	return (0);
}