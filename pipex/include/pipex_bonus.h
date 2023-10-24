/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:43:12 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define IN 0
# define OUTWRITE 1
# define OUTAPPEND 2

int		ft_start_files(int argc, char **argv, int *fdin, int *fdout);
void	ft_redirect(char *command, char **envp);
void	ft_execute(char *command, char **envp);
int		ft_open_file(char *file_path, int mode);

int		ft_strichr(const char *s, int c);
char	*ft_join_path(char *directory, char *command);
char	*ft_get_command_path(char *command_name, char **envp);
int		ft_here_doc(char **argv);

char	**ft_split_command(char const *s, char c);

#endif