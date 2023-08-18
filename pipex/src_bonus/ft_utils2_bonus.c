/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:24:30 by jumoncad          #+#    #+#             */
/*   Updated: 2023/08/18 13:39:20 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	ft_write_to_pipe(int *fd, char **argv);

int	ft_strichr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return (i);
		i++;
	}
	if (ch == '\0')
		return (i);
	return (-1);
}

char	*ft_join_path(char *directory, char *command)
{
	char	*full_path;
	int		i;
	int		j;

	full_path = malloc((ft_strlen(directory) + ft_strlen(command) + 2) * \
		sizeof(char));
	if (!full_path)
		return (NULL);
	i = 0;
	j = 0;
	while (directory[j])
		full_path[i++] = directory[j++];
	full_path[i++] = '/';
	j = 0;
	while (command[j])
		full_path[i++] = command[j++];
	full_path[i] = '\0';
	return (full_path);
}

char	*ft_get_command_path(char *command_name, char **envp)
{
	char	*path;
	char	*directory;
	char	*bin;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (ft_strdup(command_name));
	path = &envp[i][5];
	while (path && ft_strichr(path, ':') != -1)
	{
		directory = ft_strndup(path, ft_strichr(path, ':'));
		bin = ft_join_path(directory, command_name);
		free(directory);
		if (access(bin, F_OK | X_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	return (ft_strdup(command_name));
}

int	ft_here_doc(char **argv)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_print_error(3, "pipe");
	pid = fork();
	if (pid == -1)
		ft_print_error(4, "fork");
	if (pid)
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		ft_write_to_pipe(&fd[1], argv);
	}
	return (STDIN);
}

static void	ft_write_to_pipe(int *fd, char **argv)
{
	char	*line;
	char	*limiter;

	limiter = argv[2];
	write(STDIN, "pipex: here_doc> ", 17);
	while (get_next_line(0, &line))
	{
		if (!ft_strncmp(limiter, line, ft_strlen(limiter)))
			break ;
		write(*fd, line, ft_strlen(line));
		free(line);
		write(STDIN, "pipex: here_doc> ", 17);
	}
	free(line);
	close(*fd);
	exit(6);
}
