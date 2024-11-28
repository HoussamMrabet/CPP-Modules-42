/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:15:05 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/28 22:17:48 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <map>

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

AForm *createRobotomyRequestForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *createShrubberyCreationForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *createPresidentialPardonForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeForm(std::string const &name, std::string const &target)
{
    AForm *(*funcs[])(const std::string &target) = {&createRobotomyRequestForm, &createShrubberyCreationForm, &createPresidentialPardonForm};
    std::string names[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    int i = 0;
    
    while (i < 3 && names[i].compare(name))
        i++ ;
    if (i > 2)
        throw InvalidFormException();
    return ((*funcs[i])(target));
}

