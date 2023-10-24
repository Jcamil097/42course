/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:18:15 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

/******************ft_utils******************/
char		*str_ndup(char *str, unsigned int n);
char		**str_split(char *str, char sep);
int			str_ichr(char *str, char c);
char		*path_join(char *path, char *bin);

/******************pipex******************/
char		*getPath(char *cmd, char **env);
void		exec(char *cmd, char **env);
void		redir(char *cmd, char **env, int fdin);
int			openfile(char *filename, int mode);
void		pipex(char **argv, char **envp);

#endif