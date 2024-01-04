/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:59:44 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/04 17:21:56 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_fork_left);
	print(philo, "\033[1;92mhas taken a fork 🍴\033[0;39m\n");
	if (philo->info->num_philo == 1)
	{
		ft_usleep(philo->info->time_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->mut_fork_right);
	print(philo, "\033[1;92mhas taken a fork 🍴\033[0;39m\n");
}

void	philo_eat(t_philo *philo)
{
	print(philo, "\033[1;94mis eating 🍜\033[0;39m\n");
	pthread_mutex_lock(&philo->info->mutex_eat);
	philo->last_eat = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->info->mutex_eat);
	ft_usleep(philo->info->time_eat);
	pthread_mutex_unlock(philo->mut_fork_right);
	pthread_mutex_unlock(&philo->mut_fork_left);
	print(philo, "\033[1;89mis sleeping 😴\033[0;39m\n");
	ft_usleep(philo->info->time_sleep);
	print(philo, "\033[1;91mis thinking 🙇🏻‍♂️💭\033[0;39m\n");
}

void	*check_death(void *phi)
{
	t_philo *philo;

	philo = (t_philo *)phi;
	ft_usleep(philo->info->time_die + 1);
	pthread_mutex_lock(&philo->info->mutex_eat);
	pthread_mutex_lock(&philo->info->mutex_stop);
	if (!is_dead(philo, 0) && get_time()
		- philo->last_eat >= (long)philo->info->time_die)
	{
		pthread_mutex_unlock(&philo->info->mutex_eat);
		pthread_mutex_unlock(&philo->info->mutex_stop);
		print(philo, "\033[1;91mdied ☠️\033[0;39m\n");
		is_dead(philo, 1);
	}
	pthread_mutex_unlock(&philo->info->mutex_eat);
	pthread_mutex_unlock(&philo->info->mutex_stop);
	return (NULL);
}