/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:33:29 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/26 20:35:16 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * funcion para asignar suficiente memoria 
 */
void	generate_line(char **line, t_list *list)
{
	int i;
	int len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				break;
			}
			len++;
			i++; 
		}
		list = list->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return;
}
/*
 * extrae todos los caracteres de nuestro alijo y los almacena en línea.
 * deteniéndose después del primer \n que encuentra
 */
void	extract_line(t_list *list, char **line)
{
	int i;
	int j;
	
	j = 0;
	if (list == NULL)
		return;
	generate_line(line, list);
	if (*line == NULL)
		return;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				(*line)[j++] = list->content[i];
				break;
			}
			(*line)[j++] = list->content[i++];
		}
		list = list->next;
	}
	(*line)[j] = '\0';
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
 * Busca un carácter de nueva línea en la lista vinculada dada.
 */
int	find_newline(t_list *list)
{
	int		i;
	t_list	*current;

	if (list == NULL)
		return (0);
	current = ft_lstlast(list);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
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
/*
 * usar read() para añadir caracteres a la lista
 */
void read_fd(int fd, t_list **list)
{
	char *buffer;
	int readed;
	
	readed = 1;
	// found_newline falso boolean por si hay algo que leer
	while (!find_newline(*list) && readed != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return;
		readed = read(fd, buffer, BUFFER_SIZE);
		if ((*list == NULL && readed == 0) || readed == -1)
		{
			free(buffer);
			return;
		}
		buffer[readed] = '\0';
		add_to_list(list, buffer, readed);
		free(buffer);
	}
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
	t_list	*current;
	t_list	*next;

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
	current = *list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
	*list = clean_node;
}

char *get_next_line(int fd)
{
	static t_list *list;
	char 		  *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	// 1. leer fd y agregar la lista enlazada
	read_fd(fd, &list);
	if (list == NULL)
		return (NULL);
	// 2. extraer la linea del fd
	extract_line(list, &line);
	// 3. limpiar fd
	clean_stash(&list);
	if (line[0] == '\0')
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("prueba", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}