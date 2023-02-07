# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 10:26:45 by jumoncad          #+#    #+#              #
#    Updated: 2023/01/25 12:20:33 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_C = \
		main.c\
		ft_pipex.c\
		ft_path.c\
		ft_print_error.c\

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