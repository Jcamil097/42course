/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:18:01 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*ft_free_and_join(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

static int	ft_size(char *s)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (s[i] != ' ')
		counter++;
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] && s[i + 1] != ' ')
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_process_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	*s;
	char	**str;

	i = 1;
	s = ft_calloc(1, sizeof(char));
	if (!s)
		return (NULL);
	while (i < argc)
	{
		s = ft_free_and_join(s, argv[i]);
		if (i < argc - 1)
			s = ft_free_and_join(s, " ");
		i++;
	}
	stack->size = ft_size(s);
	stack->max_size = stack->size;
	str = ft_split(s, ' ');
	free(s);
	return (str);
}
