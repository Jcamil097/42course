# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 11:59:19 by jumoncad          #+#    #+#              #
#    Updated: 2023/10/04 13:13:43 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS_FILES	= 	${shell find ./src -name "*.c"}

SRCS_MAN	= 	$(SRCS_FILES)
OBJS_MAN	=	$(patsubst %.c,%.o,$(SRCS_MAN))

LIB_DIR		=	libft
HEADER		=	-I./include/push_swap.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS_MAN) include/push_swap.h
			@echo "\033[33m ⏳--Compiling libft--⏳"
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(HEADER) $(LIB_DIR)/libft.a $(OBJS_MAN) -o $(NAME)
			@echo "\033[0;92m✅--libft compiled--✅"
			@echo "\033[33m ⏳--Compiling push_swap--⏳"
			@sleep 1
			@echo "\033[0;92m✅--push_swap compiled--✅"
			@sleep 1
			@clear
			@echo "\033[0;92mUsage: ./push_swap 2 1 3 6 5 8"

%.o:		%.c libft/*.c
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@make clean -C $(LIB_DIR)
			@$(RM) $(OBJS_MAN)

fclean:		clean
			@echo "\033[0;91m❌--libft cleaned--❌"
			@make fclean -C $(LIB_DIR)
			@$(RM) $(NAME)
			@echo "\033[0;91m❌--push_swap cleaned--❌"
			@sleep 1
			@Clear

re:			fclean all

.PHONY:		all clean fclean re
