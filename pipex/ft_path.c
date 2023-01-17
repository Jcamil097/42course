/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:42:28 by jumoncad          #+#    #+#             */
/*   Updated: 2023/01/17 12:25:15 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//comparar dos cadenas de caracteres hasta na
int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] != '\0' && --n)
		{
			if (ft_isalpha(s1[i]) && ft_isalpha(s2[i]))
			{
				if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
					return (0);
			}
			else if (s2[i] == '\0')
				return (0);
			++i;
		}
		if (s1[i] == s2[i])
			return (1);
	}
	return (0);
}

char **ft_get_path(void)
{
	int	i;
	char *p;
	char **str;
	char	**env;
	i = 0;
	str = NULL;
	env = NULL;
	printf("asfas");
	while (env[i])
	{
		if ((ft_strnequ(env[i], "PATH", 4)) == 1)
		{
			//almacenar en p una copia del valor de PATH
			p = env[i];
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
