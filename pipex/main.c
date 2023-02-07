/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:27:27 by jumoncad          #+#    #+#             */
/*   Updated: 2023/01/25 12:22:04 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int main(int argc, char **argv)
{
	if (argc != 5)
		ft_print_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	else
		ft_pipex(argv[1],argv[2],argv[3],argv[4]);
	return (0);
}
