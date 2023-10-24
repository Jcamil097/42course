/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:21:26 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:39:55 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	ft_start_files(int argc, char **argv, int *fdin, int *fdout)
{
	int	i;

	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		i = 3;
		*fdin = ft_here_doc(argv);
		*fdout = ft_open_file(argv[argc - 1], OUTAPPEND);
	}
	else
	{
		i = 1;
		*fdin = ft_open_file(argv[i++], IN);
		*fdout = ft_open_file(argv[argc - 1], OUTWRITE);
	}
	return (i);
}

void	ft_execute(char *command, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;
	int		i;

	cmd_args = ft_split_command(command, ' ');
	if (ft_strchr(cmd_args[0], '/'))
		cmd_path = cmd_args[0];
	else
		cmd_path = ft_get_command_path(cmd_args[0], envp);
	execve(cmd_path, cmd_args, envp);
	i = 0;
	while (cmd_args[i])
	{
		free(cmd_args[i]);
		i++;
	}
	free(cmd_args);
	free(cmd_path);
	ft_putstr_fd(": command not found\n", STDERR);
	exit(127);
}

void	ft_redirect(char *command, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_print_error(86, "pipe");
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		waitpid(-1, NULL, WNOHANG);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		ft_execute(command, envp);
	}
}

int	ft_open_file(char *file_path, int mode)
{
	int	fd;

	if (mode == IN)
	{
		if (access(file_path, F_OK) == -1)
			return (STDIN);
		fd = open(file_path, O_RDONLY);
		if (fd == -1)
			ft_print_error(86, "Error opening file");
	}
	else if (mode == OUTWRITE)
	{
		fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			ft_print_error(86, "ERROR open");
	}
	else
	{
		fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			ft_print_error(86, "ERROR open");
	}
	return (fd);
}
