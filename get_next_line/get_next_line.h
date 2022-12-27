/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:34:08 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/27 16:33:47 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void 	read_fd(int fd, t_list **list);
int		find_newline(t_list *list);
void	extract_line(t_list *list, char **line);
void	generate_line(char **line, t_list *list);
void	free_stash(t_list *list);
t_list	*ft_lstlast(t_list *list);
void 	add_to_list(t_list **list, char *buf, int readed);
int		ft_strlen(const char *str);
void	clean_stash(t_list **list);

#endif