/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:33:29 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/27 16:34:07 by jumoncad         ###   ########.fr       */
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
	{
		free_stash(list);
		list = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	//crear archivo prueba con el texto
	fd = open("prueba", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		
		if (line == NULL)
			break ;
		free(line);
		printf("%s", line);
	}
	return (0);
}