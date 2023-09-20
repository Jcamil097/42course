/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:57:52 by jumoncad          #+#    #+#             */
/*   Updated: 2023/09/20 12:47:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen_stack(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
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

static int	ft_isnum(char *num)
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

void	ft_check_argc(int argc, char *argv[])
{
	int		i;
	int		tmp;
	char	**args;
	int		check;

	i = 0;
	check = 0;
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
		if (!ft_isnum(args[i]))
		{
			ft_putstr_fd("Error\n", 2);
			check = 1;
		}
		if (ft_duplicated(tmp, args, i))
		{
			ft_putstr_fd("Error\n", 2);
			check = 1;
		}
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			ft_putstr_fd("Error\n", 2);
			check = 1;
		}
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

void	create_stack(t_struct *data, int argc, char *argv[])
{
	int	i;

	i = 0;
	data->stack_a = malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
	{
		data->stack_a[i] = ft_atoi(argv[i + 1]);
		data->len_stack_a++;
		i++;
	}
}

int	ft_is_sorted(t_struct *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < data->len_stack_a - 1)
	{
		if (data->stack_a[i] > data->stack_a[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	create_stack_b(t_struct *data, int argc)
{
	int	i;

	i = 0;
	data->stack_b = malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
	{
		data->stack_b[i] = data->stack_a[i];
		i++;
	}
}

void	ft_sa(t_struct *data)
{
	ft_swap(&data->stack_a[0], &data->stack_a[1]);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_struct *data)
{
	ft_swap(&data->stack_b[0], &data->stack_b[1]);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_struct *data)
{
	ft_sa(data);
	ft_sb(data);
	ft_putstr_fd("ss\n", 1);
}

/* void	ft_pa(t_struct *data)
{
	int	*tmp;
	int	i;

	if (data->len_stack_b == 0)
		return ;
	i = 0;
	data->len_stack_a++;
	data->len_stack_b--;
	tmp = malloc(sizeof(int) * (data->len_stack_a));
	tmp[0] = data->stack_b[0];
	while (i < data->len_stack_a - 1)
	{
		tmp[i + 1] = data->stack_a[i];
		i++;
	}
	i = 0;
	while (i < data->len_stack_a)
	{
		data->stack_a[i] = tmp[i];
		i++;
	}
	free(tmp);
	ft_putstr_fd("pa\n", 1);
} */

void ft_pa(t_struct *data)
{
	int i;
	int j;
	
	if (data->len_stack_b == 0)
		return ;
	data->len_stack_a++;
	data->len_stack_b--;
	i = data->len_stack_a - 1;
	// Desplaza los elementos de stack_a hacia arriba en la pila
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	// Mueve el primer elemento de stack_b a stack_a
	data->stack_a[0] = data->stack_b[0];
	j = 0;
	// Desplaza los elementos de stack_b hacia abajo en la pila
	while (j < data->len_stack_b)
	{
		data->stack_b[j] = data->stack_b[j + 1];
		j++;
	}
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_struct *data)
{
	int	i;
	int	j;

	if (data->len_stack_a == 0)
		return ;
	data->len_stack_b++;
	data->len_stack_a--;
	i = data->len_stack_b - 1;
	// Desplaza los elementos de stack_b hacia arriba en la pila
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	// Mueve el primer elemento de stack_a a stack_b
	data->stack_b[0] = data->stack_a[0];
	j = 0;
	// Desplaza los elementos de stack_a hacia abajo en la pila
	while (j < data->len_stack_a)
	{
		data->stack_a[j] = data->stack_a[j + 1];
		j++;
	}
	ft_putstr_fd("pb\n", 1);
}

void	ft_ra(t_struct *data)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = data->stack_a[0];
	while (i < data->len_stack_a - 1)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	data->stack_a[data->len_stack_a - 1] = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_struct *data)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = data->stack_b[0];
	while (i < data->len_stack_b - 1)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}
	data->stack_b[data->len_stack_b - 1] = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_struct *data)
{
	ft_ra(data);
	ft_rb(data);
	ft_putstr_fd("rr\n", 1);
}

void	ft_rra(t_struct *data)
{
	int	i;
	int	tmp;

	i = data->len_stack_a - 1;
	tmp = data->stack_a[data->len_stack_a - 1];
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[0] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_struct *data)
{
	int	i;
	int	tmp;

	i = data->len_stack_b - 1;
	tmp = data->stack_b[data->len_stack_b - 1];
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[0] = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_struct *data)
{
	ft_rra(data);
	ft_rrb(data);
	ft_putstr_fd("rrr\n", 1);
}

static void	sort_3(t_struct *data)
{
	if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[0] > data->stack_a[2])
		ft_rra(data);
	else if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[1] > data->stack_a[2])
	{
		ft_sa(data);
		ft_ra(data);
	}
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[0] < data->stack_a[2])
		ft_sa(data);
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] < data->stack_a[2])
	{
		ft_rra(data);
		ft_rra(data);
	}
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] > data->stack_a[2])
	{
		ft_ra(data);
		ft_sa(data);
	}
}

static int	ft_get_min(t_struct *data, int val)
{
	int	i;
	int	min;

	i = 0;
	min = data->stack_a[0];
	while (i < data->len_stack_a)
	{
		if (data->stack_a[i] < min && data->stack_a[i] > val)
			min = data->stack_a[i];
		i++;
	}
	return (min);
}

int	ft_get_distance(t_struct *data, int min)
{
	int	i;
	int	distance;

	i = 0;
	distance = 0;
	while (data->stack_a[i] != min)
	{
		i++;
		distance++;
	}
	return (distance);
}

static void	sort_4(t_struct *data)
{
	int	distance;
	int	min;

	if (ft_is_sorted(data))
		return ;
	min = ft_get_min(data, -1);
	distance = ft_get_distance(data, min);
	if (distance == 1)
		ft_ra(data);
	else if (distance == 2)
	{
		ft_ra(data);
		ft_ra(data);
	}
	else if (distance == 3)
		ft_rra(data);
	if (ft_is_sorted(data))
		return ;
	ft_pb(data);
	sort_3(data);
	ft_pa(data);
}

static void	sort_5(t_struct *data)
{
	
	int	distance;
	int	min;

	if (ft_is_sorted(data))
		return ;
	min = ft_get_min(data, -1);
	distance = ft_get_distance(data, min);
	while (distance > 0)
	{
		ft_ra(data);
		distance--;
	}
	ft_pb(data);
	min = ft_get_min(data, -1);
	distance = ft_get_distance(data, min);
	while (distance > 0)
	{
		ft_ra(data);
		distance--;
	}
	ft_pb(data);
	sort_3(data);
 	ft_pa(data);
	ft_pa(data);
	/*ft_pa(data); */
	/* if (distance == 1)
		ft_ra(data);
	else if (distance == 2)
	{
		ft_ra(data);
		ft_ra(data);
	}
	else if (distance == 3)
		ft_rra(data);
	else if (distance == 4)
	{
		ft_rra(data);
		ft_rra(data);
	}
	if (ft_is_sorted(data))
		return ; */
	//ft_pb(data);

	int	i = 0;
	printf("stack_a:\n");
	while (i < data->len_stack_a)
	{
		printf("    ");
		printf("%d\n", data->stack_a[i]);
		i++;
	}
	i = 0;
	printf("stack_b:\n");
	while (i < data->len_stack_b)
	{
		printf("    ");
		printf("%d\n", data->stack_b[i]);
		i++;
	}
}

void	simple_sort(t_struct *data)
{
	int	size;

	if (ft_is_sorted(data) || data->len_stack_a == 1 || data->len_stack_a == 0)
		return ;
	size = data->len_stack_a;
	if (size == 2)
		ft_sa(data);
	else if (size == 3)
		sort_3(data);
	else if (size == 4)
		sort_4(data);
	else if(size == 5)
		sort_5(data);
	/* int	i = 0;
	printf("stack_a:\n");
	while (i < data->len_stack_a)
	{
		printf("    ");
		printf("%d\n", data->stack_a[i]);
		i++;
	}
	i = 0;
	printf("stack_b:\n");
	while (i < data->len_stack_b)
	{
		printf("    ");
		printf("%d\n", data->stack_b[i]);
		i++;
	} */
}

static void	sort_stack(t_struct *data)
{
	/* printf("entra");
	printf("len_stack_a: %d\n", data->len_stack_a); */
	if (data->len_stack_a <= 5)
		simple_sort(data);
	/* 	else
			radix_sort(data); */
}
int	main(int argc, char *argv[])
{
	t_struct	*data;

	if (argc < 2)
		return (-1);
	ft_check_argc(argc, argv);
	data = malloc(sizeof(t_struct));
	create_stack(data, argc, argv);
	data->stack_b = malloc(sizeof(int) * (argc - 1));
	// create_stack_b(data, argc);
	if (ft_is_sorted(data))
	{
		printf("stack_a ya ordenada\n");
		free(data);
		return (0);
	}
	sort_stack(data);
	free(data);
	// imprimir stack
	/* int i = 0;
	printf("stack_a:\n");
	while (i < argc - 1)
	{
		printf("    ");
		printf("%d\n", data->stack_a[i]);
		i++;
	} */
	return (0);
}
