# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 20:02:24 by hmrabet           #+#    #+#              #
#    Updated: 2024/06/20 20:03:01 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSP

SOURCE = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJECT = main.o Fixed.o Point.o bsp.o

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
