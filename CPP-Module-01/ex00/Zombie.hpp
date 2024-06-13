/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:02:50 by hmrabet           #+#    #+#             */
/*   Updated: 2024/06/13 17:30:07 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie(std::string name);
	void	announce(void);
	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);
	~Zombie();
};

#endif