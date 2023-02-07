/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:18:35 by jumoncad          #+#    #+#             */
/*   Updated: 2023/02/07 12:06:27 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
prueba
*/
void ft_pid1(int fd1, int *piped, char *cmd1)
{
	char **comand1;
	char	**env;
	printf("asfa");
	comand1 = ft_split(cmd1, ' ');
	dup2(fd1, 0);
	dup2(piped[1], 1);
	close(fd1);
	close(piped[0]);
	close(piped[1]);
	
	if (comand1[0][0] == '/')
	{
		if (execve(comand1[0], comand1, env) == -1)
			ft_print_error("No such command, try removing the /\n");	
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
	char	**env;
	wait (NULL);
	comand2 = ft_split(cmd2, ' ');
	dup2(piped[0], 0);
	dup2(fd2, 1);
	close(fd2);
	close(piped[0]);
	close(piped[1]);
	if (comand2[0][0] == '/')
	{
		if (execve(comand2[0], comand2, env) == -1)
			ft_print_error("No such command, try removing the /\n");	
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
		ft_print_error("File open failure\n");
	/* 
	O_WRONLY: abre el archivo sólo para escritura
    O_CREAT: si el archivo no existe, se crea
    O_TRUNC: si el archivo existe y está abierto para escritura, su tamaño se trunca a cero bytes
    0666: indica los permisos del archivo creado */	
	if ((fd2 = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0777)) < 0)
		ft_print_error("File open failure\n");
	if ((pid = fork()) == -1)
		ft_print_error("process creation error\n");
	else if (pid == 0)
		ft_pid1(fd1, piped, cmd1);
	if ((pid = fork()) == -1)
		ft_print_error("Error\n");
	else if (pid == 0)
		ft_pid2(fd2, piped, cmd2);
	close(fd1);
	close(fd2);
	close(piped[0]);
	close(piped[1]);
}

/* 
	char *argv[] = {"ls", "-l", "/", NULL};
    char *envp[] = {NULL};
    ft_print_error("Ejecutando comando ls -l /\n");
    execve("/bin/ls", argv, envp);
    perror("execve"); 
*/
int main(int argc, char **argv)
{
	if (argc != 5)
		ft_print_error("Usage: ./pipex file1 cmd1 cmd2 file2\n\n");
	else
		ft_pipex(argv[1], argv[2], argv[3], argv[4]);
    return (0);
}
