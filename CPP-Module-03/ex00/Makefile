# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 20:09:37 by hmrabet           #+#    #+#              #
#    Updated: 2024/06/23 09:42:06 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

SOURCE = main.cpp ClapTrap.cpp

OBJECT = main.o ClapTrap.o

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)

%.o : %.c Makefile ClapTrap.hpp
	$(CPP) -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
