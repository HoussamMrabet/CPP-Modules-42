/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:19:58 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 16:27:51 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

static int	generateGrade(void)
{
	std::srand(std::time(0));
    return (1 + (rand() % 150));
}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (this->gradeSign < 1 || this->gradeExec < 1)
		throw GradeTooHighException();
	else if (this->gradeSign > 150 || this->gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm() : name("blank"), isSigned(false), gradeSign(generateGrade()), gradeExec(generateGrade()) {}

AForm::AForm(AForm const &f) : name(f.getName()), isSigned(f.getIsSigned()), gradeSign(f.getGradeSign()), gradeExec(f.getGradeExec()) {}

AForm::~AForm() {}

AForm	&AForm::operator=(AForm const &f)
{
	if (this != &f)
		this->isSigned = f.getIsSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const AForm &f)
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

std::string		AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIsSigned() const
{
	return (this->isSigned);
}

int		AForm::getGradeSign() const
{
	return (this->gradeSign);
}

int		AForm::getGradeExec() const
{
	return (this->gradeExec);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (this->getIsSigned())
		throw SignedException();
	if (b.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	this->isSigned = true;
}

const char *	AForm::GradeTooHighException::what() const throw()
{
	return (" grade is higher than required!");
}

const char *	AForm::GradeTooLowException::what() const throw()
{
	return (" grade is lower than required!");
}

const char *	AForm::SignedException::what() const throw()
{
	return (" is already signed!");
}

const char *	AForm::NotSignedException::what() const throw()
{
	return (" is not signed!");
}
