/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:23:51 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 16:37:06 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;

	public:

		AMateria();
        AMateria(const AMateria &objs);
		AMateria(std::string const & type);
        AMateria &operator=(const AMateria & objs);
        virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
