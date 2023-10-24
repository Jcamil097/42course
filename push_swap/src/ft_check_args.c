/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:02:20 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

static void	ft_valid_args(char *argv)
{
	int	i;
	int	consecutive_signs;

	i = 0;
	consecutive_signs = 1;
	while (argv[i])
	{
		if (ft_is_sign(argv[i]) && argv[i - 1] != ' ' && i != 0)
			ft_error(NULL, NULL, NULL);
		if (ft_is_sign(argv[i]) && !ft_isdigit(argv[i + 1]))
			ft_error(NULL, NULL, NULL);
		if (ft_isdigit(argv[i]) || argv[i] == ' ')
			consecutive_signs = 0;
		if (ft_is_sign(argv[i]) && consecutive_signs < 2)
			consecutive_signs++;
		if (!ft_isdigit(argv[i]) && !ft_is_sign(argv[i]) && argv[i] != ' ')
			ft_error(NULL, NULL, NULL);
		i++;
	}
}

static int	ft_is_only_spaces(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_error(NULL, NULL, NULL);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (ft_is_only_spaces(argv[i]))
			ft_error(NULL, NULL, NULL);
		ft_valid_args(argv[i]);
		i++;
	}
}
