/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:18:35 by jumoncad          #+#    #+#             */
/*   Updated: 2023/01/14 15:11:58 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
char	**env;
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

	i = 0;
	str = NULL;
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
			i = -1;
			break ;
		}
		else
			i++;
	}
	return (str);
}

void ft_exec(char **argv)
{
	char **path;
	char *buf;
	int	 i;
	
	i = 0;
	path = ft_get_path();
	while (path[i])
	{
		buf = ft_cont(path[i], argv[0]);
		if (execve(buf, argv, env) != -1)
		{
			i = -1;
			break ;
		}
		else
			i++;
	}
	if (i >= 0)
	{
		printf("error");
	}
	
}

void ft_pid1(int fd1, int *piped, char *cmd1)
{
	char **comand1;

	comand1 = ft_split(cmd1, ' ');
	dup2(fd1, 0);
	dup2(piped[1], 1);
	close(fd1);
	close(piped[0]);
	close(piped[1]);
	if (comand1[0][0] == '/')
	{
		if (execve(comand1[0], comand1, env) == -1)
			printf("No such command, try removing the /\n");	
	}
	else
		ft_exec(comand1);
	close(fd1);
	close(piped[0]);
	close(piped[1]);
}

void ft_pid2(int fd2, int *piped, char *cmd2)
{
	char **comand2;

	comand2 = ft_split(cmd2, ' ');
	dup2(fd2, 0);
	dup2(piped[1], 1);
	close(fd2);
	close(piped[0]);
	close(piped[1]);
	if (comand2[0][0] == '/')
	{
		if (execve(comand2[0], comand2, env) == -1)
			printf("No such command, try removing the /\n");	
	}
	else
		ft_exec(comand2);
	close(fd2);
	close(piped[0]);
	close(piped[1]);
}

void	ft_pipex(char *input, char *cmd1, char *cmd2, char *output)
{
	/*
	pid_t
	es un tipo de dato que se utiliza 
	para almacenar el identificador de proceso (PID) 
	en sistemas operativos Unix y Linux. 
	*/
	pid_t	pid;
	int		fd1;
	int		fd2;
	int		piped[2];

	pipe(piped);
	if ((fd1 = open(input, O_RDONLY)) < 0)
		printf("File open failure\n");
	/* 
	O_WRONLY: abre el archivo sólo para escritura
    O_CREAT: si el archivo no existe, se crea
    O_TRUNC: si el archivo existe y está abierto para escritura, su tamaño se trunca a cero bytes
    0666: indica los permisos del archivo creado */
	if ((fd2 = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
		printf("File open failure\n");
	if ((pid = fork()) == -1)
		printf("process creation error\n");
	else if (pid == 0)
		ft_pid1(fd1, piped, cmd1);
	if ((pid = fork()) == -1)
		printf("Errror\n");
	else if (pid == 0)
		ft_pid2(fd2, piped, cmd2);
	close(fd1);
	close(fd2);
	close(piped[0]);
	close(piped[1]);
}


int main(int argc, char **argv)
{
	if (argc != 5)
		printf("Usage: ./pipex file1 cmd1 cmd2 file2\n\n");
	else
		ft_pipex(argv[1], argv[2], argv[3], argv[4]);
	/* 
	char *argv[] = {"ls", "-l", "/", NULL};
    char *envp[] = {NULL};
    printf("Ejecutando comando ls -l /\n");
    execve("/bin/ls", argv, envp);
    perror("execve"); 
	*/
    return (0);
}