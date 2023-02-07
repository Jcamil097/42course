/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:31:50 by jumoncad          #+#    #+#             */
/*   Updated: 2023/02/07 12:01:01 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/*
esta función ejecuta un primer comando y 
redirige la entrada y la salida estándar para que se pueda conectar 
a una tubería y comunicarse con el segundo comando en la función ft_pid2.
*/
void	ft_pid1(int fd1, int *piped, char *cmd1)
{
	/*
	dup = para duplicar un descriptor de archivos, presentando dos o mas 
		  descriptores diferentes
	dup2 = duplica un descriptor existente	  
	*/
	char **command1;
	
	command1 = ft_split(cmd1, ' ');
	dup2(fd1, 0);
	dup2(piped[1], 1);
	close(fd1);
	close(piped[0]);
	close(piped[1]);
	if (command1[0][0] == '/')
	{
		if (execve(command1[0], command1, environ) == -1)
			ft_print_error("No such command, try removing the /\n");
	}
	else
		ft_exec(command1);
	close(fd1);
	close(piped[0]);
	close(piped[1]);
}

void 	ft_pid2(int fd2, int *piped, char *cmd2)
{
	char	**command2;

	wait (NULL);
	command2 = ft_split(cmd2, ' ');
	dup2(piped[0], 0);
	dup2(fd2, 1);
	close(piped[0]);
	close(piped[1]);
	close(fd2);
	if (command2[0][0] == '/')
	{
		if (execve(command2[0], command2, environ) == -1)
			ft_print_error("No such command, try removing the /\n");
	}
	else
		ft_exec(command2);
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

	/* 
	O_WRONLY: abre el archivo sólo para escritura
    O_CREAT: si el archivo no existe, se crea
    O_TRUNC: si el archivo existe y está abierto para escritura, su tamaño se trunca a cero bytes
    0666: indica los permisos del archivo creado
	pipe = "|" abre dos descriptores de fichero y almacena su valor en los dos enteros que contiene el array de descriptores de fichero
	 */	
	pipe(piped);
	if ((fd1 = open(input, O_RDONLY)) < 0)
		ft_print_error("File open failure\n");
	if ((fd2 = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
		ft_print_error("File open failure\n");
	if ((pid = fork()) == -1)
		ft_print_error("Process creation error\n");
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
