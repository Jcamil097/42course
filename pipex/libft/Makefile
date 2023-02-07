# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 10:03:47 by jumoncad          #+#    #+#              #
#    Updated: 2023/01/25 12:50:57 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_memcpy.c ft_split.c ft_strdup.c ft_strlcpy.c \
					ft_strlen.c ft_substr.c ft_isalpha.c ft_putchar_fd.c \
					ft_putstr_fd.c ft_strnequ.c ft_tolower.c ft_strcat.c
					
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