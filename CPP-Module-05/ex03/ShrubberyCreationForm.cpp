/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:42:21 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 20:08:00 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();

	std::ofstream outFile(this->target + "_shrubbery");

    if (!outFile.is_open())
		throw std::ios_base::failure("Shrubbery failed to open file for writing ASCII trees inside it!");

    const std::string tree =
		"         *         \n"
		"        & &        \n"
		"       && &&       \n"
		"      &&& &&&      \n"
		"     &&&&&&&&&     \n"
        "    &&&&&&&&&&&    \n"
        "   &&&&&&&&&&&&&   \n"
        "  &&&&&&&&&&&&&&&  \n"
        " &&&&&&&&&&&&&&&&& \n"
        "&&&&&&&&&&&&&&&&&&&\n"
        "   |    |||    |   \n"
        "   $    |||    $   \n"
        "        |||        \n"
        "*******************\n"
        "*******************\n";

    outFile << tree;
    outFile.close();
}
