# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 04:09:02 by hmrabet           #+#    #+#              #
#    Updated: 2024/09/02 10:22:53 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

SOURCE = main.cpp PhoneBook.cpp Contact.cpp

OBJECT = main.o PhoneBook.o Contact.o

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)

%.o : %.cpp Makefile PhoneBook.hpp Contact.hpp
	$(CPP) -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
