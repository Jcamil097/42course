/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:02:20 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/06 12:16:18 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_is_duplicate(int *array, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (array[i] == array[j] && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_parse_args(char **str, t_stack *stack)
{
	long	number;
	int		i;
	int		j;
	int		*array;

	array = ft_calloc((stack->size + 1), sizeof(int));
	if (!array)
		return (NULL);
	i = stack->size - 1;
	j = 0;
	while (i >= 0)
	{
		number = ft_atoi(str[j++]);
		if (number > 2147483647 || number < -2147483648)
			ft_error(str, stack, array);
		array[i--] = (int)number;
	}
	if (ft_is_duplicate(array, stack))
		ft_error(str, stack, array);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (array);
}

static void	ft_are_args_valid(char *argv)
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
		ft_are_args_valid(argv[i]);
		i++;
	}
}
