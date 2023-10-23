/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:28:31 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/10 12:29:27 by jumoncad         ###   ########.fr       */
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
	i = 0;
	j = 0;
	while (i < stack->size)
	{
		number = ft_atoi(str[j++]);
		if (number > 2147483647 || number < -2147483648)
			ft_error(str, stack, array);
		array[i++] = (int)number;
	}
	if (ft_is_duplicate(array, stack))
		ft_error(str, stack, array);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (array);
}
