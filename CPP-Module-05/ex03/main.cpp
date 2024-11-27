/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:00:00 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 20:04:30 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat  b("hmrabet", 1);
        Intern intern;
        AForm* rrf;
        AForm* invalid;
        
        rrf = intern.makeForm("shrubbery creation", "tree");

        std::cout << *rrf << std::endl;

        b.signForm(*rrf);
        b.executeForm(*rrf);
        
        delete rrf;

        invalid = intern.makeForm("invalid form", "invalid");
        
        std::cout << *invalid << std::endl;
        
        b.signForm(*invalid);
        b.executeForm(*invalid);
        
        delete invalid;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}