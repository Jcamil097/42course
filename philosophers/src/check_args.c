/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:13:19 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/25 13:43:42 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_spaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				valorfinal;
	long long int	nbr;

	nbr = 0;
	i = 0;
	valorfinal = 1;
	while (str[i] && ft_spaces(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			valorfinal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
		if (nbr < INT_MIN && valorfinal == -1)
			return (0);
		if (nbr > INT_MAX && valorfinal == 1)
			return (-1);
	}
	return (nbr * valorfinal);
}

void	free_split(char **argv)
{
	int	i;

	i = 1;
	if (argv[0] == NULL)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

char	**arg_error_check(char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ')
				exit_and_message("ERROR; only positive numbers are valid\n");
			j++;
		}
		j = 0;
		i++;
	}
	if (i == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv[4] || argv[6])
		{
			free_split(argv);
			exit_and_message("Error: wrong number of arguments\n");
		}
	}
	return (argv);
}

void	check_arg_limits(char **argv)
{
	if (ft_atoi(argv[1]) == 0)
		exit_and_message("ERROR; there must be atleast 1 philo\n");
	if (ft_atoi(argv[1]) > 200)
		exit_and_message("ERROR; max philo number is 200\n");
	if (ft_atoi(argv[2]) == 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[2]) < 60)
		exit_and_message("ERROR; time to die \n");
	if (ft_atoi(argv[3]) == 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[2]) < 60)
		exit_and_message("ERROR; time to eat \n");
	if (ft_atoi(argv[4]) == 0|| ft_atoi(argv[2]) < 0 || ft_atoi(argv[2]) < 60)
		exit_and_message("ERROR; time to sleep \n");
	if (argv[5] && ft_atoi(argv[5]) == 0)
		exit_and_message("ERROR; number of times to eat \n");
}
