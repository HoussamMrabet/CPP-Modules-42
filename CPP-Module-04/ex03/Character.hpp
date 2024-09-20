/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:05:08 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 16:11:35 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];

	public:
		Character();
        Character(const std::string &name);
        Character(const Character &objs);
        Character &operator=(const Character &Objs);
        ~Character();

        std::string const &getName() const;
        void equip(AMateria * m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif