/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:09:50 by jumoncad          #+#    #+#             */
/*   Updated: 2023/04/05 17:16:13 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int main(int argc, char **argv, char **envp)
{
	int f1;
	int f2;
	
	if(argc != 5)
		return (ft_putstr("numero de argumentos invalidos",0));
	if(check_empty(argv[2]) || check_empty(argv[3]))
		return (1);
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		return (ft_putstr(strerror(errno), argv[1]));
	if (f2 < 0)
		return (ft_putstr(strerror(errno), argv[4]));
	pipex(f1, f2, argv, envp);
	if(close(f1) < 0 || close(f2) < 0)
		return (ft_putstr(strerror(errno), 0));
	return (0);
}