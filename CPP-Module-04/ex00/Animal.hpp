/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:44:32 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/08 22:56:24 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(const Animal &animal);
		Animal &operator=(const Animal &animal);
		virtual ~Animal();

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
