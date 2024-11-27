/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:15:05 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 20:32:01 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char		*Intern::InvalidFormException::what() const throw()
{
	return ("The form you are trying to create doesn't exist!");
}

Intern::Intern() {}

Intern::Intern(Intern const &intern)
{
    (void)intern;    
}

Intern& Intern::operator=(Intern const &intern)
{
    (void)intern;
	return (*this);
}

Intern::~Intern() {}

AForm   *Intern::makeForm(std::string const &name, std::string const &target)
{
    if (!name.compare("robotomy request"))
        return (new RobotomyRequestForm(target));
    else if (!name.compare("shrubbery creation"))
        return (new ShrubberyCreationForm(target));
    else if (!name.compare("presidential pardon"))
        return (new PresidentialPardonForm(target));
    else
        throw InvalidFormException();
}

