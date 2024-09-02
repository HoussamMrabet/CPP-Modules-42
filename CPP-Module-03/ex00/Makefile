# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 20:09:37 by hmrabet           #+#    #+#              #
#    Updated: 2024/09/02 10:24:14 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

SOURCE = main.cpp ClapTrap.cpp

OBJECT = main.o ClapTrap.o

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)

%.o : %.cpp Makefile ClapTrap.hpp
	$(CPP) -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
