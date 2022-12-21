# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 11:29:59 by jumoncad          #+#    #+#              #
#    Updated: 2022/12/19 17:47:54 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	ft_printf.c ft_print_p.c ft_print_u.c ft_print_x.c \
					ft_utils.c
					
OBJS			= $(SRCS:.c=.o)
				
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

AR   			= ar rcs

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
				
.PHONY:			all clean fclean