/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:45:37 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/04 17:25:11 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *phi)
{
	t_philo		*philo;
	pthread_t	thread;

	philo = (t_philo *)phi;
	if (philo->num % 2 == 0)
		ft_usleep(philo->info->time_eat / 10);
	while (!is_dead(philo, 0))
	{
		pthread_create(&thread, NULL, check_death, phi);
		take_forks(philo);
		philo_eat(philo);
		pthread_detach(thread);
		if (philo->eat_count == philo->info->num_eat)
		{
			pthread_mutex_lock(&philo->info->mutex_stop);
			if (++philo->info->philo_eat == philo->info->num_philo)
			{
				pthread_mutex_unlock(&philo->info->mutex_stop);
				is_dead(philo, 2);
			}
			pthread_mutex_unlock(&philo->info->mutex_stop);
			return (NULL);
		}
	}
	return (NULL);
}

void	ft_pthread_join(t_info *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return ;
		i++;
	}
}

int	philo_init(t_info *data)
{
	int	i;

	data->time_start = get_time();
	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].num = i + 1;
		data->philo[i].last_eat = 0;
		data->philo[i].mut_fork_right = NULL;
		data->philo[i].info = data;
		data->philo[i].eat_count = 0;
		pthread_mutex_init(&data->philo[i].mut_fork_left, NULL);
		if (i == data->num_philo - 1)
			data->philo[i].mut_fork_right = &data->philo[0].mut_fork_left;
		else
			data->philo[i].mut_fork_right = &data->philo[i + 1].mut_fork_left;
		if (pthread_create(&data->philo[i].thread, NULL, &routine,
				&data->philo[i]) != 0)
			return (-1);
		i++;
	}
	ft_pthread_join(data);
	return (0);
}
