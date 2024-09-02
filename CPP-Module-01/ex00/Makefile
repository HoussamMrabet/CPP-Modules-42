# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 17:32:15 by hmrabet           #+#    #+#              #
#    Updated: 2024/09/02 10:23:04 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

SOURCE = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJECT = main.o Zombie.o newZombie.o randomChump.o

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
