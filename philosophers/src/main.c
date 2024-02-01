/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:08:43 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/30 13:41:50 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	exit_and_message(char *message)
{
	printf("%s", message);
	exit(1);
}

t_rules	init_struct(char **argv)
{
	t_rules	rules;
	int		i;

	i = 0;
	rules.num_of_philo = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	rules.num_philo_eat = -1;
	if (argv[5])
		rules.num_philo_eat = ft_atoi(argv[5]);
	if (!argv[0])
		free_split(argv);
	rules.start_time = ft_get_time();
	rules.forks = malloc(sizeof(pthread_mutex_t) * rules.num_of_philo);
	while (i < rules.num_of_philo)
	{
		pthread_mutex_init(&rules.forks[i], NULL);
		i++;
	}
	return (rules);
}

void	philos_aux(t_rules rules, t_philosopher *philos, int i)
{
	philos[i].left_fork = &rules.forks[i];
	if (i != 0)
		philos[i].rigth_fork = &rules.forks[i - 1];
	else
		philos[i].rigth_fork = &rules.forks[rules.num_of_philo - 1];
	philos[i].id = i + 1;
	philos[i].eaten = 0;
	philos[i].rules = &rules;
}

void	init_philos(t_rules rules, t_philosopher *philos, int i, int all_alive)
{
	pthread_mutex_t	*all_alive_mutex;
	pthread_t		*thread;

	thread = malloc(sizeof(pthread_t) * rules.num_of_philo);
	all_alive_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(all_alive_mutex, NULL);
	philos = malloc(sizeof(t_philosopher) * (rules.num_of_philo));
	while (i < rules.num_of_philo)
	{
		philos_aux(rules, philos, i);
		philos[i].all_alive = &all_alive;
		philos[i].all_alive_mutex = all_alive_mutex;
		philos[i].thread = thread[i];
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
		i++;
	}
	while (i--)
		pthread_join(philos[i].thread, NULL);
	pthread_mutex_destroy(all_alive_mutex);
	free(all_alive_mutex);
	free(rules.forks);
	free(thread);
	free(philos);
}

int	main(int argc, char *argv[])
{
	t_rules			rules;
	t_philosopher	*philos;
	int				i;
	int				all_alive;

	if (argc != 2 && argc != 5 && argc != 6)
		exit_and_message("Error: Wrong number of arguments\n");
	argv = arg_error_check(argv, 1);
	check_arg_limits(argv);
	rules = init_struct(argv);
	i = 0;
	all_alive = 1;
	philos = NULL;
	init_philos(rules, philos, i, all_alive);
	return (0);
}
