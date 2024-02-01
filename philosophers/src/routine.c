/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:17:48 by jumoncad          #+#    #+#             */
/*   Updated: 2024/02/01 13:05:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor(void	*arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->philo_data_mutex);
		if (philo->eaten == philo->rules->num_philo_eat)
			break ;
		if (ft_get_time() - philo->last_eat > philo->rules->time_to_die)
		{			
			pthread_mutex_lock(philo->all_alive_mutex);
			if (*philo->all_alive > 0)
			{
				*philo->all_alive = -1;
				printf("%ld %d died\n",
					ft_get_time() - philo->rules->start_time, philo->id);
			}
			pthread_mutex_unlock(philo->all_alive_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->philo_data_mutex);
	}
	return (NULL);
}

void	routine_philo_extension(t_philosopher *philo)
{
	philo->last_eat = ft_get_time();
	philo->philo_data_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->philo_data_mutex, NULL);
	if (philo->id % 2 == 0)
		ft_msleep(philo->rules->time_to_eat - 1);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;
	long			print_time;
	int				print_id;
	pthread_t		monitor_thread;

	philo = (t_philosopher *)arg;
	print_time = philo->rules->start_time;
	print_id = philo->id;
	routine_philo_extension(philo);
	monitor_thread = malloc(sizeof(pthread_t));
	philo->monitor_thread = monitor_thread;
	pthread_create(&philo->monitor_thread, NULL, monitor, philo);
	while (1)
	{
		if (ft_eat(philo, print_id, print_time) < 0)
			break ;
	}
	pthread_join(philo->monitor_thread, NULL);
	free(monitor_thread);
	pthread_mutex_destroy(philo->philo_data_mutex);
	pthread_mutex_destroy(philo->left_fork);
	free(philo->philo_data_mutex);
	return (NULL);
}
