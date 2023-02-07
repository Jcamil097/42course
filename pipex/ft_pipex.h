/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:27:57 by jumoncad          #+#    #+#             */
/*   Updated: 2023/02/03 11:37:38 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <fcntl.h>
#include "libft/libft.h"

extern char	**environ;

void	ft_pipex(char *input, char *cmd1, char *cmd2, char *output);
void	ft_print_error(char *str);
void	ft_pid1(int fd1, int *piped, char *cmd1);
void	ft_pid2(int fd2, int *piped, char *cmd2);
void	ft_exec(char **argv);

#endif
