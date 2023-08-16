# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 12:19:17 by jumoncad          #+#    #+#              #
#    Updated: 2023/08/15 13:00:02 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS_FILES	= 	${shell find ./src -name "*.c"}
BONUS_FILES	= 	${shell find ./src_bonus -name "*.c"}

SRCS_MAN	= 	$(SRCS_FILES)
OBJS_MAN	=	$(patsubst %.c,%.o,$(SRCS_MAN))

SRCS_BONUS	= 	$(BONUS_FILES)
OBJS_BONUS	=	$(patsubst %.c,%.o,$(SRCS_BONUS))

LIB_DIR		=	libft
HEADER		=	-I./include/pipex.h
HEADER_B	=	-I./include/pipex_bonus.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS_MAN) include/pipex.h
			@echo "\033[33m----Compiling libft----"
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(HEADER) $(LIB_DIR)/libft.a $(OBJS_MAN) -o $(NAME)
			@#clear

bonus:		$(OBJS_BONUS) include/pipex_bonus.h
			@echo "\033[33m----Compiling libft----"
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(HEADER_B) $(LIB_DIR)/libft.a $(OBJS_BONUS) -o $(NAME)
			@#clear


%.o:		%.c libft/*.c
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@make clean -C $(LIB_DIR)
			@$(RM) $(OBJS_MAN)
			@$(RM) $(OBJS_BONUS)

fclean:		clean
			@make fclean -C $(LIB_DIR)
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
