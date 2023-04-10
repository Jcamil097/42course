/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:25:40 by jumoncad          #+#    #+#             */
/*   Updated: 2023/04/10 14:55:34 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*ft_join(char *dst, const char *src)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	r = malloc(sizeof(char)
			* (ft_strlen(src) + ft_strlen(dst) + 1));
	if (!r)
		return (NULL);
	while (dst[++i])
		r[i] = dst[i];
	while (src[++j])
		r[i++] = src[j];
	r[i] = '\0';
	return (r);
}

static void child_one(int *pipefd, t_cmd *c, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	// Establecer los descriptores de archivo para la entrada y salida estándar del proceso hijo.
	// c->f es el descriptor de archivo para la redirección de entrada, mientras que pipefd[1] es el descriptor de archivo para la redirección de salida.
	//STDIN_FILENO = 0
	//STDOUT_FILENO = 1
	//EXIT_SUCCESS = 0
	//EXIT_FAILURE = 1
	if (dup2(c->f, STDIN_FILENO) < 0
		|| dup2(pipefd[1], STDOUT_FILENO) < 0)
		// Si se produce un error al establecer los descriptores de archivo, imprimir un mensaje de error y salir de la función.
		return (perror("Child one"));
	// Cerrar el descriptor de archivo de lectura en el extremo del pipe, ya que no se usará en este proceso.
	close(pipefd[0]);
	// Iterar a través de los caminos de búsqueda en la estructura del comando.
	while (c->path[++i])
	{
		// Crear la ruta completa del comando utilizando el camino actual y el nombre del comando.
		cmd = ft_join(c->path[i], c->cmd);
		if (!cmd)
			// Si no se puede crear la ruta completa del comando, salir de la función.
			return ;
		// Ejecutar el comando utilizando execve().
		if (execve(cmd, c->args, envp) != -1)
		{
			// Si execve() devuelve -1, significa que el comando no se pudo ejecutar correctamente.
			// Liberar la memoria asignada a la ruta completa del comando y salir del proceso hijo con un código de salida EXIT_SUCCESS.
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		// Si execve() devuelve aquí, significa que el comando no se pudo ejecutar con éxito utilizando el camino actual.
		// Liberar la memoria asignada a la ruta completa del comando y continuar con el siguiente camino en la estructura del comando.
		free(cmd);
	}
	// Si el bucle termina, significa que el comando no se pudo ejecutar utilizando ninguno de los caminos de búsqueda especificados.
	// Salir del proceso hijo con un código de salida EXIT_FAILURE.
	exit(EXIT_FAILURE);
}

static void	child_two(int *pipefd, t_cmd *c, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(c->f, STDOUT_FILENO) < 0
		|| dup2(pipefd[0], STDIN_FILENO) < 0)
		return (perror("Child two"));
	close(pipefd[1]);
	while (c->path[++i])
	{
		cmd = ft_join(c->path[i], c->cmd);
		if (!cmd)
			return ;
		if (execve(cmd, c->args, envp) != -1)
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		free(cmd);
	}
	exit(EXIT_FAILURE);
}

void	exec_cmd(t_cmd *cmd1, t_cmd *cmd2, char **envp)
{
	int		status;
	int		pipefd[2];
	pid_t	p1;
	pid_t	p2;

	status = 0;
	pipe(pipefd);
	p1 = fork();
	if (p1 < 0)
		return (perror("Fork one"));
	if (!p1)
		child_one(pipefd, cmd1, envp);
	p2 = fork();
	if (p2 < 0)
		return (perror("Fork two"));
	if (!p2)
		child_two(pipefd, cmd2, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

int	check_cmd(t_cmd *c)
{
	int		i;
	char	*cmd;

	i = -1;
	while (c->path[++i])
	{
		cmd = ft_join(c->path[i], c->cmd);
		if (!cmd)
			return (0);
		if (access(cmd, X_OK) != -1)
		{
			free(cmd);
			return (1);
		}			
		free(cmd);
	}
	error_msg(c->cmd);
	return (0);
}
