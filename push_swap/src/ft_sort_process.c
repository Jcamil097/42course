/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:58:59 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_sort_two(t_stack *stack)
{
	if (ft_is_sorted(stack))
		return ;
	if (stack->stack[0] > stack->stack[1])
		ft_s(stack, 'a');
}

static void	ft_sort_three(t_stack *stack)
{
	if (ft_is_sorted(stack))
		return ;
	if (stack->stack[0] > stack->stack[1])
	{
		if (stack->stack[1] < stack->stack[stack->size - 1]
			&& stack->stack[stack->size - 1] < stack->stack[0])
			ft_rotate(stack, 'a');
		else
			ft_s(stack, 'a');
	}
	if (stack->stack[stack->size - 1] < stack->stack[0]
		&& stack->stack[0] < stack->stack[1])
		ft_reverse_rotate(stack, 'a');
	if (stack->stack[0] < stack->stack[stack->size - 1]
		&& stack->stack[stack->size - 1] < stack->stack[1])
	{
		ft_s(stack, 'a');
		ft_sort_three(stack);
	}
}

static void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	ft_insert_min_int_to_top(stack_a, 'a');
	ft_pb(stack_a, stack_b);
	if (!ft_is_sorted(stack_a))
		ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

static void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	ft_insert_min_int_to_top(stack_a, 'a');
	ft_pb(stack_a, stack_b);
	ft_insert_min_int_to_top(stack_a, 'a');
	ft_pb(stack_a, stack_b);
	if (!ft_is_sorted(stack_a))
		ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_init_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size == 2)
		ft_sort_two(stack_a);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else if (stack_a->size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		ft_sort_five(stack_a, stack_b);
	else if (stack_a->size <= 120)
		ft_quick_sort(stack_a, stack_b, 18);
	else
		ft_quick_sort(stack_a, stack_b, 50);
	ft_print_instruction("");
}
