/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:00:00 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/22 23:46:32 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat hmrabet("hmrabet", 50);
        Bureaucrat houbet("houbet", 1);
        Bureaucrat houssam("houssam", 150);

        std::cout << hmrabet;
        std::cout << houbet;
        std::cout << houssam;

        Form taxForm("Tax Declaration", 40, 20);
        Form contractForm("Contract Agreement", 70, 50);
		Form defaultF;

        std::cout << defaultF;
        std::cout << taxForm;
        std::cout << contractForm;

        hmrabet.signForm(taxForm);
        houbet.signForm(taxForm);
        houssam.signForm(contractForm);

        std::cout << taxForm;
        std::cout << contractForm;

        houbet.signForm(taxForm);

        try
        {
            Form invalidForm("Invalid Form", 151, 10);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            Form invalidForm2("Invalid Form 2", 10, 0);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
