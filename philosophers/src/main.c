/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:38:37 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/04 17:21:41 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	freeall(t_info *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_destroy(&data->philo[i].mut_fork_left);
		pthread_mutex_destroy(data->philo[i].mut_fork_right);
	}
	free(data->philo);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->mutex_stop);
	pthread_mutex_destroy(&data->mutex_eat);
	pthread_mutex_destroy(&data->mutex_dead);
}

int	check_argv(char **argv)
{
	int	num;

	num = ft_atoi(argv[1]);
	if (num < 2 || num > 200)
		return (1);
	num = ft_atoi(argv[2]);
	if (num < 60)
		return (1);
	num = ft_atoi(argv[3]);
	if (num < 60)
		return (1);
	num = ft_atoi(argv[4]);
	if (num < 60)
		return (1);
	if (argv[5])
	{
		num = ft_atoi(argv[5]);
		if (num < 1)
			return (1);
	}
	return (0);
}

int	var_init(t_info *data, char **argv)
{
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->mutex_stop, NULL);
	pthread_mutex_init(&data->mutex_eat, NULL);
	pthread_mutex_init(&data->mutex_dead, NULL);
	data->stop = 0;
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (data->philo == NULL)
		return (2);
	if (check_num(argv))
	{
		printf("Error: invalid arguments.\n");
		return (1);
	}
	data->philo_eat = 0;
	data->num_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_eat = ft_atoi(argv[5]);
	if (argv[5] && data->num_eat == 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	data;

	if (argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (check_argv(argv))
	{
		printf("Error: wrong argument\n");
		return (1);
	}
	if (var_init(&data, argv) == 1)
	{
		free(data.philo);
		return (0);
	}
	philo_init(&data);
	freeall(&data);
	return (0);
}
