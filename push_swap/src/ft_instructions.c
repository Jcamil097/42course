/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:54:12 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/02 13:14:10 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_b->size == 0)
		return ;
	stack_a->size += 1;
	stack_b->size -= 1;
	temp = stack_b->stack[0];
	ft_memmove(stack_b->stack, stack_b->stack + 1, stack_b->size * sizeof(int));
	ft_memmove(stack_a->stack + 1, stack_a->stack, stack_a->size * sizeof(int));
	stack_a->stack[0] = temp;
	ft_print_instruction("pa");
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_a->size == 0)
		return ;
	stack_b->size += 1;
	stack_a->size -= 1;
	temp = stack_a->stack[0];
	ft_memmove(stack_b->stack + 1, stack_b->stack, stack_b->size * sizeof(int));
	ft_memmove(stack_a->stack, stack_a->stack + 1, stack_a->size * sizeof(int));
	stack_b->stack[0] = temp;
	ft_print_instruction("pb");
}

void	ft_rotate(t_stack *stack, char c)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->stack[0];
	(void) c;
	ft_memmove(stack->stack, stack->stack + 1, stack->size * sizeof(int));
	stack->stack[stack->size - 1] = temp;
	if (c == 'a')
		ft_print_instruction("ra");
	else if (c == 'b')
		ft_print_instruction("rb");
}

void	ft_reverse_rotate(t_stack *stack, char c)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->stack[stack->size - 1];
	ft_memmove(stack->stack + 1, stack->stack, stack->size * sizeof(int));
	stack->stack[0] = temp;
	if (c == 'a')
		ft_print_instruction("rra");
	else if (c == 'b')
		ft_print_instruction("rrb");
}

void	ft_s(t_stack *stack, char c)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = temp;
	if (c == 'a')
		ft_print_instruction("sa");
	else if (c == 'b')
		ft_print_instruction("sb");
}
