# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 16:29:46 by hmrabet           #+#    #+#              #
#    Updated: 2024/06/16 16:31:34 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl

SOURCE = main.cpp Harl.cpp

OBJECT = main.o Harl.o

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
