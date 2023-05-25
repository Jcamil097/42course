# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2023/05/25 14:12:14 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
OBJ_DIR = obj/
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f
HFILE 	= include/so_long.h

GREEN	=	"\\x1b[32m"
RED		=	"\\x1b[31m"

SRC_FILES = src/libft.c \
 src/check_map.c \
 src/ft_itoa.c \
 src/map_hook.c \
 src/move.c \
 src/render_img.c \
 src/save_map.c \
 src/main.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HFILE)
	@make -C mlx
	@$(CC) $(CFLAGS)  -Imlx -I$(HFILE) -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRC_FILES) -o $(NAME)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ_FILES) obj
	@printf \
	"                                                                       \n"
	@printf \
	"$(GREEN)-------------- Compiled --------------\n\n"
	
clean: 
	@rm -rf $(OBJ_DIR)
	
fclean: clean 
	@$(RM) $(NAME)
	@make -C mlx/ clean
	@echo "\n${RED}---------------------- Cleaned! ----------------------\n"
	
re : fclean all

.PHONY: all clean fclean re
