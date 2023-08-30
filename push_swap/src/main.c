/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:57:52 by jumoncad          #+#    #+#             */
/*   Updated: 2023/08/30 13:22:09 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstsize(t_struct *head)
{
	size_t	i;
	t_struct	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_struct	*ft_lstnew(int value)
{
	t_struct	*new;

	new = (t_struct *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_struct	*ft_lstlast(t_struct *head)
{
	t_struct	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_lstadd_back(t_struct **stack, t_struct *new)
{
	t_struct	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

static int	ft_duplicated(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void ft_check_argc(int argc, char *argv[])
{
	int		i;
	int		tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if(!ft_isnum(args[i]))
			ft_putstr_fd("Error\n", 2);
		if(ft_duplicated(tmp, args, i))
			ft_putstr_fd("Error\n", 2);
		if(tmp < -2147483648 || tmp > 2147483647)
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

static t_struct	*get_next_min(t_struct **stack)
{
	t_struct	*head;
	t_struct	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	ft_index_stack(t_struct **stack)
{
	t_struct	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

static void ft_init_stack(t_struct **stack, int argc, char *argv[])
{
	t_struct	*tmp;
	int	i;
	char	**args;

	i = 0;
	if(argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while(args[i])
	{
		tmp = ft_lstnew(ft_atoi(args[i]));//crea un nodo con el valor de la cadena en int
		ft_lstadd_back(stack, tmp);//añade el nodo al final de la lista
		i++;
	}
	
	/*******revisar*******/
	//ft_index_stack(stack);

	if (argc == 2)
		ft_free(args);
	/* i = 1;
	while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	} */
}

int	ft_is_sorted(t_struct **stack)
{
	t_struct	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_simple_sort(t_struct **stack_a, t_struct **stack_b)
{
	int	size;

	if (ft_is_sorted(stack_a) || ft_lstsize(*stack_a) == 0 || ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

static void	sort_stack(t_struct **stack_a, t_struct **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		ft_simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int main(int argc, char *argv[])
{
	t_struct	**stack_a;
	t_struct	**stack_b;
	
	if (argc < 2)
		return (-1);
	ft_check_argc(argc, argv);
	stack_a = (t_struct **)malloc(sizeof(t_struct));
	stack_b = (t_struct **)malloc(sizeof(t_struct));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_init_stack(stack_a, argc, argv);
	if (ft_is_sorted(*stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	ft_sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
