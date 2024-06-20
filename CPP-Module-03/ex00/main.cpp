/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:09:35 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/20 20:47:01 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap houbet("houbet");
	
	houbet.attack("hmrabet");
	houbet.takeDamage(8);
	houbet.beRepaired(2);
	houbet.attack("hmrabet");
	houbet.takeDamage(4);
	houbet.beRepaired(2);
	houbet.attack("hmrabet");
	
	return (0);
}