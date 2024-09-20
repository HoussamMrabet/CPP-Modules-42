# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 14:44:10 by hmrabet           #+#    #+#              #
#    Updated: 2024/09/20 13:56:02 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal

SOURCE = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJECT = main.o Animal.o Dog.o Cat.o Brain.o

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)

%.o : %.cpp Makefile Animal.hpp Dog.hpp Cat.hpp Brain.hpp
	$(CPP) -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
