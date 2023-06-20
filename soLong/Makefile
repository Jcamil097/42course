# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2023/06/20 13:59:12 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

INCS		:= 	include/so_long.h

LIBS		:= mlx
LIBS_TARGET	+= libraries/mlx/libmlx.a
MFLAGS		:= -framework OpenGL -framework AppKit

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

SRC_DIR     := src
SRCS        := animation.c \
            draw.c \
            ft_itoa.c \
            ft_split.c \
            gameplay.c \
            get_next_line.c \
            init.c \
            libft_str.c \
            map_validate.c \
            moves.c \
            player_update.c \
            so_long.c
			
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= obj
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= cc
CFLAGS		:= -g3 -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I,$(INCS))
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))

RM			:= rm -f
RF			:= rm -rf
DIR_DUP		= mkdir -p $(@D)

.SILENT:
all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) $(MFLAGS) -o $(NAME)
	@echo "$(GREEN)░██████╗░█████╗░██╗░░░░░░█████╗░███╗░░██╗░██████╗░"
	@echo "$(GREEN)██╔════╝██╔══██╗██║░░░░░██╔══██╗████╗░██║██╔════╝░"
	@echo "$(GREEN)╚█████╗░██║░░██║██║░░░░░██║░░██║██╔██╗██║██║░░██╗░"
	@echo "$(GREEN)░╚═══██╗██║░░██║██║░░░░░██║░░██║██║╚████║██║░░╚██╗"
	@echo "$(GREEN)██████╔╝╚█████╔╝███████╗╚█████╔╝██║░╚███║╚██████╔╝"
	@echo "$(GREEN)╚═════╝░░╚════╝░╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░"
	@echo "$(YELLOW)\n !Use this command ./so_long assets/maps/<map_name>.ber\n$(DEF_COLOR)" 
	
$(LIBS_TARGET):
	@$(MAKE) -C $(@D) 2> /dev/null

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)
	@echo "$(RED)░█████╗░██╗░░░░░███████╗░█████╗░███╗░░██╗███████╗██████╗░"
	@echo "$(RED)██╔══██╗██║░░░░░██╔════╝██╔══██╗████╗░██║██╔════╝██╔══██╗"
	@echo "$(RED)██║░░╚═╝██║░░░░░█████╗░░███████║██╔██╗██║█████╗░░██║░░██║"
	@echo "$(RED)██║░░██╗██║░░░░░██╔══╝░░██╔══██║██║╚████║██╔══╝░░██║░░██║"
	@echo "$(RED)╚█████╔╝███████╗███████╗██║░░██║██║░╚███║███████╗██████╔╝"
	@echo "$(RED)░╚════╝░╚══════╝╚══════╝╚═╝░░╚═╝╚═╝░░╚══╝╚══════╝╚═════╝░"
	
fclean: clean
	$(RM) $(NAME)
	$(RF) ./fdf.dSYM
	$(RF) $(BUILD_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
