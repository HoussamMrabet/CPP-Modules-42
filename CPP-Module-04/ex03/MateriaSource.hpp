/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:42:12 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/20 16:34:34 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *learnedAMateria[4];

    public:
    MateriaSource();
    MateriaSource(const MateriaSource &objs);
    MateriaSource &operator=(const MateriaSource & objs);
    ~MateriaSource();

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif
