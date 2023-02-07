/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:35:31 by jumoncad          #+#    #+#             */
/*   Updated: 2023/02/07 12:04:43 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/*
Esta función es una función en C que construye una 
ruta de acceso a un archivo específico en el sistema de archivos. 
Toma dos argumentos: una cadena str que representa una ruta de acceso 
y una cadena filname que representa el nombre de archivo. 
Concatena la ruta de acceso y el nombre de archivo para crear una ruta completa y, 
a continuación, asigna este valor a un puntero de caracteres buf. 
Finalmente, la función devuelve el puntero de caracteres buf que contiene 
la ruta completa.
*/
void	*ft_count(char *str, char *filname)
{
	char *buf;

	buf = (char *)malloc(ft_strlen(str) + ft_strlen(filname) + 16);
	ft_strcat(buf, str);
	ft_strcat(buf, "/");
	ft_strcat(buf, filname);
	return (buf);
}

/*
e utiliza para obtener la variable de entorno PATH en un sistema operativo. 
Esta variable de entorno es una lista de directorios separados por ':' 
en los que se buscan programas ejecutables.
*/

char **ft_get_path(void)
{
	int		i;
	char	*p;
	char	**str;

	i = 0;
	str = NULL;
	while (environ[i])
	{
		if (ft_strnequ(environ[i], "PATH", 4) == 1)
		{
			//almacenar en p una copia del valor de PATH
			p = environ[i];
			//desplazar el puntero 5 espacios para ignorar "PATH="
			p += 5;
			//dividir el valor de PATH
			str = ft_split(p, ':');
			//salir del bucle una vez se ha encontrado y procesado PATH
			i = -34;
			break ;
		}
		else
			i++;
	}
	return (str);
}

/*
busca el comando que se le pasa como argumento en el PATH del sistema 
y lo ejecuta utilizando la función execve
*/
void	ft_exec(char **argv)
{
	char	**path;
	char	*buf;
	int		i;

	i = 0;
	path = ft_get_path();
	while (path[i])
	{
		buf = ft_count(path[i], argv[0]);
		if (execve(buf, argv, environ) != -1)
		{
			i = -34;
			break ;
		}
		else
			i++;
	}
	if (i >= 0)
		ft_print_error("Could not find command\n");
}
