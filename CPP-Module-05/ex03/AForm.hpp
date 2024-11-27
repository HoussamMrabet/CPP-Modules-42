/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:20:45 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 16:27:30 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;
		
	public:
		AForm();
		AForm(const std::string &name, int gradeSign, int gradeExec);
		AForm(const AForm &f);
		AForm	&operator=(const AForm &f);
		virtual ~AForm();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;

		void	beSigned(const Bureaucrat &b);
		
		virtual void	execute(Bureaucrat const &executor) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class SignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &f);

#endif