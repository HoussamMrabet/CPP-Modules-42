/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:19:58 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/25 22:42:05 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

static int	generateGrade(void)
{
	std::srand(std::time(0));
    return (1 + (rand() % 150));
}

Form::Form(const std::string &name, int gradeSign, int gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (this->gradeSign < 1 || this->gradeExec < 1)
		throw GradeTooHighException();
	else if (this->gradeSign > 150 || this->gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form() : name("blank"), isSigned(false), gradeSign(generateGrade()), gradeExec(generateGrade()) {}

Form::Form(Form const &f) : name(f.getName()), isSigned(f.getIsSigned()), gradeSign(f.getGradeSign()), gradeExec(f.getGradeExec()) {}

Form::~Form() {}

Form	&Form::operator=(Form const &f)
{
	if (this != &f)
		this->isSigned = f.getIsSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Form &f)
{
	out << "Form infos:" << std::endl;
	out << "Name : " << f.getName() << std::endl;
	out << "Signed : ";
	if (f.getIsSigned())
		out << "True" << std::endl;
	else
		out << "False" << std::endl;
	out << "Grade for signing : " << f.getGradeSign() << std::endl;
	out << "Grade for executing : " << f.getGradeExec() << std::endl;
	return (out);
}

std::string		Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->isSigned);
}

int		Form::getGradeSign() const
{
	return (this->gradeSign);
}

int		Form::getGradeExec() const
{
	return (this->gradeExec);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else
		this->isSigned = true;
}

const char *	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is higher than required!");
}

const char *	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is lower than required!");
}