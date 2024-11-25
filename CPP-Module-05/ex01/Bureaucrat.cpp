/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:54 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/25 22:41:09 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static int	generateGrade(void)
{
	std::srand(std::time(0));
    return (1 + (rand() % 150));
}

const char		*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade can't be higher than 1!");
}

const char		*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade can't be lower than 150!");
}

Bureaucrat::Bureaucrat(void) : name("unknown"), grade(generateGrade()) {}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.getName()), grade(b.getGrade()) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat&			Bureaucrat::operator=(const Bureaucrat	&b)
{
	if (this != &b)
		this->grade = b.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void				Bureaucrat::incrementGrade(void)
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void				Bureaucrat::decrementGrade(void)
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

void				Bureaucrat::signForm(Form& form)
{
	try
	{
		if (form.getIsSigned())
		{
			std::cout << "Form " << this->name << " is already signed." << std::endl; 
			return ;
		}
		form.beSigned(*this);
		std::cout << "Bureaucrat " << this->name << " signed the form " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Bureaucrat " << this->name << " couldn’t sign the form " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}
