/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:47:57 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/05 11:41:42 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_max(t_stack *stack)
{
	int	i;
	int	max;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	max = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	ft_find_next_max(t_stack *stack, int max)
{
	int	i;
	int	next_max;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next_max = INT_MIN;
	while (i < stack->size)
	{
		if (stack->stack[i] > next_max && stack->stack[i] < max)
			next_max = stack->stack[i];
		i++;
	}
	return (next_max);
}

static void	ft_insert_and_push(t_stack *stack_a, t_stack *stack_b, int first,
		int second)
{
	ft_insert_int_to_top(stack_b, 'b', first);
	ft_pa(stack_a, stack_b);
	ft_insert_int_to_top(stack_b, 'b', second);
	ft_pa(stack_a, stack_b);
}

static void	ft_push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	first;
	int	second;
	int	first_index;
	int	second_index;

	while (stack_b->size)
	{
		first = ft_find_max(stack_b);
		second = ft_find_next_max(stack_b, first);
		first_index = ft_get_index(stack_b, first);
		second_index = ft_get_index(stack_b, second);
		if (first_index > stack_b->size / 2)
			first_index = stack_b->size - first_index;
		if (second_index > stack_b->size / 2)
			second_index = stack_b->size - second_index;
		if (first_index < second_index)
			ft_insert_and_push(stack_a, stack_b, first, second);
		else
			ft_insert_and_push(stack_a, stack_b, second, first);
		if (stack_a->stack[0] > stack_a->stack[1])
			ft_s(stack_a, 'a');
	}
}

void	ft_quick_sort(t_stack *stack_a, t_stack *stack_b, int quick_size)
{
	int	index;
	int	min;
	int	cont;

	while (stack_a->size)
	{
		cont = 0;
		min = ft_get_min(stack_a);
		while (cont++ < quick_size)
		{
			min = ft_find_next_min_int(stack_a, min);
			if (cont == quick_size / 2)
				stack_a->middle = min;
		}
		cont = 0;
		while (cont++ < quick_size)
		{
			index = ft_get_min_index(stack_a, min);
			ft_insert_int_to_top(stack_a, 'a', stack_a->stack[index]);
			ft_pb(stack_a, stack_b);
			if (stack_b->stack[0] < stack_a->middle)
				ft_rotate(stack_b, 'b');
		}
	}
	ft_push_b_to_a(stack_a, stack_b);
}
