/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:31:40 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/10 12:33:43 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_print_instruction(char *action)
{
	if ((!ft_strcmp(action, "sa") && !ft_strcmp(action, "sb"))
		|| (!ft_strcmp(action, "sb") && !ft_strcmp(action, "sa")))
		ft_print("ss");
	else if ((!ft_strcmp(action, "ra") && !ft_strcmp(action, "rb"))
		|| (!ft_strcmp(action, "rb") && !ft_strcmp(action, "ra")))
		ft_print("rr");
	else if ((!ft_strcmp(action, "rra") && !ft_strcmp(action, "rrb"))
		|| (!ft_strcmp(action, "rrb") && !ft_strcmp(action, "rra")))
		ft_print("rrr");
	else
	{
		if (ft_strcmp(action, ""))
			ft_print(action);
	}
}

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
