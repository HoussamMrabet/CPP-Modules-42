# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 20:02:24 by hmrabet           #+#    #+#              #
#    Updated: 2024/09/02 10:24:07 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSP

SOURCE = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJECT = main.o Fixed.o Point.o bsp.o

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)

%.o : %.cpp Makefile Fixed.hpp Point.hpp
	$(CPP) -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
