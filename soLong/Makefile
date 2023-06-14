# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2023/06/14 18:48:16 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
OBJ_DIR = obj/
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f
HFILE 	= include/so_long.h

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

SRC_FILES = src/animation.c \
			src/draw.c \
			src/ft_itoa.c \
			src/ft_split.c \
			src/gameplay.c \
			src/get_next_line.c \
			src/init.c \
			src/libft_str.c \
			src/map_validate.c \
			src/moves.c \
			src/player_update.c \
			src/so_long.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HFILE)
	@make -C libraries/mlx
	@$(CC) $(CFLAGS) -Imlx -I$(HFILE) -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRC_FILES) -o $(NAME)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ_FILES) obj
	@echo "$(GREEN)░██████╗░█████╗░██╗░░░░░░█████╗░███╗░░██╗░██████╗░"
	@echo "$(GREEN)██╔════╝██╔══██╗██║░░░░░██╔══██╗████╗░██║██╔════╝░"
	@echo "$(GREEN)╚█████╗░██║░░██║██║░░░░░██║░░██║██╔██╗██║██║░░██╗░"
	@echo "$(GREEN)░╚═══██╗██║░░██║██║░░░░░██║░░██║██║╚████║██║░░╚██╗"
	@echo "$(GREEN)██████╔╝╚█████╔╝███████╗╚█████╔╝██║░╚███║╚██████╔╝"
	@echo "$(GREEN)╚═════╝░░╚════╝░╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░"
	@echo "$(YELLOW)\n !Use this command ./so_long assets/maps/<map_name>.ber\n$(DEF_COLOR)" 
	
clean: 
	@rm -rf $(OBJ_DIR)
	
fclean: clean 
	@$(RM) $(NAME)
	@make -C libraries/mlx/ clean
	@echo "$(RED)░█████╗░██╗░░░░░███████╗░█████╗░███╗░░██╗███████╗██████╗░"
	@echo "$(RED)██╔══██╗██║░░░░░██╔════╝██╔══██╗████╗░██║██╔════╝██╔══██╗"
	@echo "$(RED)██║░░╚═╝██║░░░░░█████╗░░███████║██╔██╗██║█████╗░░██║░░██║"
	@echo "$(RED)██║░░██╗██║░░░░░██╔══╝░░██╔══██║██║╚████║██╔══╝░░██║░░██║"
	@echo "$(RED)╚█████╔╝███████╗███████╗██║░░██║██║░╚███║███████╗██████╔╝"
	@echo "$(RED)░╚════╝░╚══════╝╚══════╝╚═╝░░╚═╝╚═╝░░╚══╝╚══════╝╚═════╝░"
re : fclean all

.PHONY: all clean fclean re
