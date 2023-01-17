# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 10:17:29 by jumoncad          #+#    #+#              #
#    Updated: 2023/01/17 11:56:23 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_C = ft_pipex.c ft_path.c ft_print_error.c ft_exec.c

SRC_O = $(subst .c,.o,$(SRC))

all:	$(NAME)


$(NAME):
	make -C ./libft/
	gcc -Wall -Wextra -Werror -pedantic	-o $(NAME) $(SRC_C) libft/libft.a

clean:
	make -C ./libft/ clean
	/bin/rm -f $(SRC_O)

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all