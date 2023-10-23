/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:38:27 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/10 12:32:57 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_min_index(t_stack *stack, int min)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] <= min)
			break ;
		i++;
	}
	return (i);
}

int	ft_find_next_min_int(t_stack *stack, int min)
{
	int	i;
	int	next_min;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next_min = INT_MAX;
	while (i < stack->size)
	{
		if (stack->stack[i] > min && stack->stack[i] < next_min)
			next_min = stack->stack[i];
		i++;
	}
	return (next_min);
}

int	ft_get_min(t_stack *stack)
{
	int	i;
	int	min;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	min = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

void	ft_insert_min_int_to_top(t_stack *stack, char c)
{
	int	i;
	int	min;

	if (!stack || !stack->stack)
		return ;
	i = 0;
	min = ft_get_min(stack);
	while (stack->stack[i] != min)
		i++;
	if (i <= stack->size / 2)
	{
		while (stack->stack[0] != min)
			ft_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != min)
			ft_reverse_rotate(stack, c);
	}
}
