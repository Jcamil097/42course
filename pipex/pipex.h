/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:17:44 by jumoncad          #+#    #+#             */
/*   Updated: 2023/01/17 12:04:52 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
#define	FT_PIPEX_H

#include <stdio.h>
#include <stdlib.h>	
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

extern char	**env;

int		main(int argc, char **argv);
void	ft_pipex(char *input, char *cmd1, char *cmd2, char *output);
void	ft_pid2(int fd2, int *piped, char *cmd2);
void	ft_pid1(int fd1, int *piped, char *cmd1);


int		ft_strnequ(char const *s1, char const *s2, size_t n);
char 	**ft_get_path(void);

char 	*ft_strcat(char *s1, const char *s2);
char 	*ft_cont(char *str, char *filname);
void 	ft_exec(char **argv);


void	ft_print_error(char *str);

#endif
