/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:19:30 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && str_ichr(path, ':') > -1)
	{
		dir = str_ndup(path, str_ichr(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += str_ichr(path, ':') + 1;
	}
	return (cmd);
}

void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = str_split(cmd, ' ');
	if (str_ichr(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(args[0], env);
	if (!path)
		exit(127);
	execve(path, args, env);
	ft_putstr_fd("pipex: ", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd(": command not found\n", STDERR);
	exit(127);
}

void	redir(char *cmd, char **env, int fdin)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_print_error(86, "ERROR pipe");
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		waitpid(pid, NULL, WNOHANG);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		else
			exec(cmd, env);
	}
}

int	openfile(char *filename, int mode)
{
	int	fd;

	if (mode == INFILE)
	{
		if (access(filename, F_OK) == -1)
		{
			ft_putstr_fd("pipex: ", STDERR);
			ft_putstr_fd(filename, STDERR);
			ft_putstr_fd(": No such file or directory\n", STDERR);
			return (STDIN);
		}
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			ft_print_error(86, "ERROR open");
	}
	else
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			ft_print_error(86, "ERROR open");
	}
	return (fd);
}

void	pipex(char **argv, char **envp)
{
	int	fdin;
	int	fdout;

	fdin = openfile(argv[1], INFILE);
	fdout = openfile(argv[4], OUTFILE);
	dup2(fdin, STDIN);
	dup2(fdout, STDOUT);
	redir(argv[2], envp, fdin);
	exec(argv[3], envp);
}
