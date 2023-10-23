/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:59:15 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/10 12:29:52 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (1);
	splitted = ft_process_args(argc, argv, stack_a);
	stack_a->stack = ft_parse_args(splitted, stack_a);
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (1);
	stack_b->stack = ft_calloc(stack_a->size, sizeof(int));
	if (!stack_b->stack)
		return (1);
	stack_b->size = 0;
	if (!ft_is_sorted(stack_a))
		ft_init_sort(stack_a, stack_b);
	ft_free_all_stacks(stack_a, stack_b);
	return (0);
}
