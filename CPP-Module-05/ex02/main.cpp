/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:00:00 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 16:57:34 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try {
        Bureaucrat b1("Bureaucrat1", 5);
        Bureaucrat b2("Bureaucrat2", 100);
        Bureaucrat b3("Bureaucrat3", 150);
        std::cout << b1 << b2 << b3;

        PresidentialPardonForm ppf("Target1");
        RobotomyRequestForm rrf("Target2");
        ShrubberyCreationForm scf("Target3");

        std::cout << ppf << rrf << scf;

        b1.executeForm(ppf);
        
        b3.signForm(ppf);

        b1.signForm(ppf);
        b2.signForm(scf);
        b1.signForm(rrf);

        std::cout << ppf << rrf << scf;

        b3.executeForm(ppf);

        b1.executeForm(ppf);
        b2.executeForm(scf);
        b1.executeForm(rrf);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}