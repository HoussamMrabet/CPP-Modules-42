# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 04:09:02 by hmrabet           #+#    #+#              #
#    Updated: 2024/06/12 18:42:59 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

SOURCE = main.cpp PhoneBook.cpp Contact.cpp

OBJECT = main.o PhoneBook.o Contact.o

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)

%.o : %.c Makefile
	$(CPP) -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean