# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 12:07:26 by jumoncad          #+#    #+#              #
#    Updated: 2024/02/01 13:06:04 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc -Wall -Werror -Wextra -g3 #-fsanitize=thread 

RM = rm -f

SRCS = ${shell find ./src -name "*.c"}

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

limpito: all clean

re:	fclean all

.PHONY:	all clean fclean re