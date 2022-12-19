# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 10:03:47 by jumoncad          #+#    #+#              #
#    Updated: 2022/12/17 11:36:33 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_putchar_fd.c ft_strchr.c ft_putnbr_fd.c ft_putstr_fd.c \
					ft_strchr.c ft_strlen.c ft_itoa.c ft_calloc.c ft_bzero.c
					
OBJS			= $(SRCS:.c=.o)
				
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
				
.PHONY:			all clean fclean