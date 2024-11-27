/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:20:45 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 14:51:19 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;
		
	public:
		Form();
		Form(const std::string &name, int gradeSign, int gradeExec);
		Form(const Form &f);
		Form	&operator=(const Form &f);
		~Form();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;

		void	beSigned(const Bureaucrat &b);
		
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
		class SignStateException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &f);

#endif