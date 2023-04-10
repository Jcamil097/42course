# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 12:27:28 by jumoncad          #+#    #+#              #
#    Updated: 2023/04/10 13:11:22 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror

GREEN			=	"\\x1b[32m"
YELLOW			=	"\\x1b[33m"
RED				=	"\\x1b[31m"

INC = ./inc/pipex.h \
	
SRC = \
	./src/main.c \
	./src/pipex.c \
	./src/pipex_utils.c \
	./src/utils.c \
	./src/ft_splitpath.c \
	./src/free.c \
	
OBJ = $(SRC:.c=.o)

all: 	$(NAME)

$(NAME): 	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@printf \
	"                                                                       \n"
	@printf \
	"$(GREEN)-------------- Compiled --------------\n\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	@rm -rf $(OBJ)

fclean: clean
	@echo "\n${RED}---------------------- Cleaned! ----------------------\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re