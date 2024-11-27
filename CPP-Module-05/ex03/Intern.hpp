/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:51:10 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/27 20:30:15 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
		Intern(Intern const &intern);
        ~Intern();

		Intern	&operator=(Intern const &intern);
		
        AForm   *makeForm(std::string const &name, std::string const &target);

		class InvalidFormException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif