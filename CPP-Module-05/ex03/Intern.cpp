/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:15:05 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 22:27:24 by hmrabet          ###   ########.fr       */
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
    const std::map<std::string, AForm* (*)(const std::string&)> formCreators = 
        {
            {"robotomy request", createRobotomyRequestForm},
            {"shrubbery creation", createShrubberyCreationForm},
            {"presidential pardon", createPresidentialPardonForm}
        };

    std::map<std::string, AForm* (*)(const std::string&)>::const_iterator it = formCreators.find(name);
    
    if (it == formCreators.end())
        throw InvalidFormException();

    return (it->second(target));
}

