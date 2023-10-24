/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonuc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:32:05 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;
	int	i;

	if (argc < 5 || (!ft_strncmp(argv[1], "here_doc", 8) && argc < 6))
		ft_print_error(22, "Error: invalid number of arguments");
	else
	{
		i = ft_start_files(argc, argv, &fdin, &fdout);
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		ft_redirect(argv[i++], envp);
		while (i < argc - 2)
			ft_redirect(argv[i++], envp);
		ft_execute(argv[i], envp);
	}
	return (0);
}
