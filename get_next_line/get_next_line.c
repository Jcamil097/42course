/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:48:30 by jumoncad          #+#    #+#             */
/*   Updated: 2023/11/16 13:43:50 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// devuelve la longitud de la cadena s sin contar el \0 final
char	*ft_get_line(char *str1)
{
	int		i;
	char	*str;

	i = 0;
	if (!str1[i])
		return (NULL);
	// buscamos el salto de linea o el final de la linea
	while (str1[i] && str1[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	// guardamos la linea en str hasta el salto de linea o el final de la linea
	while (str1[i] && str1[i] != '\n')
	{
		str[i] = str1[i];
		i++;
	}
	//si hay salto de linea guardamos el salto de linea en str
	if (str1[i] == '\n')
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// guarda el resto de la linea anterior en stat_point
char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	// buscamos el salto de linea o el final de la linea
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	// guardamos el resto de la linea en str
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}
// lee el fichero y guarda el resto de la linea anterior en stat_point
char	*ft_read_to_static_point(int fd, char *stat_point)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	//miestras no haya salto de linea y no lleguemos al final del fichero leemos
	while (!ft_strchr(stat_point, '\n') && read_bytes != 0)
	{
		// leemos el fichero
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(stat_point);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		if (!stat_point)
			stat_point = ft_strdup("");
		//guardamos el resto de la linea anterior en stat_point
		stat_point = ft_strjoin(stat_point, buff);
	}
	free(buff);
	return (stat_point);
}

char	*get_next_line(int fd)
{
	char *line;
	// variable estatica para guardar el resto de la linea anterior
	static char *stat_point;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	// leemos el fichero y guardamos el resto de la linea anterior en stat_point
	stat_point = ft_read_to_static_point(fd, stat_point);
	if (!stat_point)
		return (NULL);
	// guardamos la linea en line y la devolvemos
	line = ft_get_line(stat_point);          
	// guardamos el resto de la linea en stat_point
	stat_point = ft_new_left_str(stat_point);
	return (line);
}