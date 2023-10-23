/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:53 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/10 12:31:17 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_a);
	free(stack_b->stack);
	free(stack_b);
}

void	ft_error(char **splitted, t_stack *stack, int *array)
{
	int	i;

	i = 0;
	if (array)
		free(array);
	if (splitted)
	{
		while (splitted[i])
			free(splitted[i++]);
		free(splitted);
	}
	if (stack)
	{
		free(stack->stack);
		free(stack);
	}
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
