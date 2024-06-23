# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 17:58:26 by hmrabet           #+#    #+#              #
#    Updated: 2024/06/23 09:42:44 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

SOURCE = main.cpp Fixed.cpp

OBJECT = main.o Fixed.o

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)

%.o : %.c Makefile Fixed.h
	$(CPP) -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
