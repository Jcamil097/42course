/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:33:43 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/27 15:42:25 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_stash(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
/* 
 * Devuelve un puntero al último nodo de nuestro alijo 
 */
t_list	*ft_lstlast(t_list *list)
{
	t_list	*current;

	current = list;
	while (current && current->next)
		current = current->next;
	return (current);
}
/*
 * añadir al final de la list
 */
void add_to_list(t_list **list, char *buf, int readed)
{
	int i;
	t_list *last;
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*list == NULL)
	{
		*list = new_node;
		return;
	}
	last = ft_lstlast(*list);
	last->next = new_node;
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

/*
 * Después de extraer la línea que se leyó, ya no necesitamos esos caracteres
 * Esta función borra el alijo para que solo los caracteres que no se hayan 
 * devuelto al final de get_next_line permanezcan en nuestro alijo estático
 */
void	clean_stash(t_list **list)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (list == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*list);
	*list = clean_node;
}