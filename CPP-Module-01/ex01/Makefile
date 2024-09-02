# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 22:00:08 by hmrabet           #+#    #+#              #
#    Updated: 2024/09/02 10:23:10 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombies

SOURCE = main.cpp Zombie.cpp zombieHorde.cpp

OBJECT = main.o Zombie.o zombieHorde.o

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)

%.o : %.cpp Makefile Zombie.hpp
	$(CPP) -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
