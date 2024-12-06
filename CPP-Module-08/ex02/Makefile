# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 23:39:31 by hmrabet           #+#    #+#              #
#    Updated: 2024/12/07 00:09:27 by hmrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MutantStack

SOURCE = main.cpp

OBJECT = $(SOURCE:.cpp=.o)

HEADERS = MutantStack.hpp MutantStack.tpp

CPP = @c++ -Wall -Wextra -Werror -std=c++98

GREEN = \033[32m
RESET = \033[0m

define PRINT_LOADING
	@printf "$(GREEN)Compiling... ["
	@for i in $(shell seq 0 10 100); do 		printf "▓"; 		sleep 0.1; 	done
	@printf "] 100%%$(RESET)\n"
endef

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)
	@echo "$(GREEN)Your program is ready!$(RESET)"

%.o : %.cpp Makefile $(HEADERS)
	@echo "$(GREEN) $<"
	@$(PRINT_LOADING)
	$(CPP) -c $< -o $@

clean :
	@rm -f $(OBJECT)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean
