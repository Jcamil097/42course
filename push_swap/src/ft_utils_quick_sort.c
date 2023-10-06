/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_quick_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:20:00 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/05 11:39:45 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_index(t_stack *stack, int number)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == number)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_insert_int_to_top(t_stack *stack, char c, int number)
{
	int	index;

	index = ft_get_index(stack, number);
	if (index == -1)
		return ;
	if (index <= stack->size / 2)
	{
		while (stack->stack[0] != number)
			ft_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != number)
			ft_reverse_rotate(stack, c);
	}
}
