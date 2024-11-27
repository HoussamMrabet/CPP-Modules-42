/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:40:16 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 17:17:30 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
	std::cout << "some drilling noises" << std::endl;
	std::srand(std::time(0));
    if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}
