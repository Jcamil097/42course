# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 10:50:07 by jumoncad          #+#    #+#              #
#    Updated: 2024/01/04 17:37:11 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

SRCS = 	${shell find ./src -name "*.c"}

$(NAME) :
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "\033[0;92m✅--P̲h̲i̲l̲o̲s̲o̲p̲h̲e̲r̲ compiled--✅"
	@echo "$(YELLOW)\n!Use this command ./philo 5 500 100 100 [1]\n$(DEF_COLOR)"
	@echo "$(YELLOW)philosophers / time_to_die / time_to_eat / time_to_sleep / [number_of_times_each_philosopher_must_eat]\n$(DEF_COLOR)"

all : $(NAME)

clean :
	@$(RM) $(NAME)

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[0;91m❌--P̲h̲i̲l̲o̲s̲o̲p̲h̲e̲r̲  cleaned--❌"
	@sleep 1
	@Clear

re : fclean all

.PHONY : all clean fclean re