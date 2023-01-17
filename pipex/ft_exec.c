/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:44:48 by jumoncad          #+#    #+#             */
/*   Updated: 2023/01/17 12:27:33 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char *ft_cont(char *str, char *filname)
{
	char *buf;

	buf = (char *)malloc(ft_strlen(str) + ft_strlen(filname) + 16);
	ft_strcat(buf, str);
	ft_strcat(buf, "/");
	ft_strcat(buf, filname);
	return (buf);
}

void ft_exec(char **argv)
{
	char **path;
	char *buf;
	int	 i;
	char	**env;
	printf("pru");
	i = 0;
	path = ft_get_path();
	
	while (path[i])
	{
		buf = ft_cont(path[i], argv[0]);
		if (execve(buf, argv, env) != -1)
		{
			i = -34;
			break ;
		}
		else
			i++;
	}
	if (i >= 0)
	{
		ft_print_error("error");
	}
}
