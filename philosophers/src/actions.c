/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:09:28 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/30 13:01:18 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_think(t_philosopher *philo)
{
	if (check_all_alive(*philo) < 0)
		return (-1);
	pthread_mutex_lock(philo->philo_data_mutex);
	print_routine(*philo, 4, philo->rules->start_time, philo->id);
	pthread_mutex_unlock(philo->philo_data_mutex);
	return (1);
}

void	ft_sleep(t_philosopher *philo)
{
	if (check_all_alive(*philo) < 0)
		return ;
	pthread_mutex_lock(philo->philo_data_mutex);
	print_routine(*philo, 3, philo->rules->start_time, philo->id);
	ft_msleep(philo->rules->time_to_sleep);
	pthread_mutex_unlock(philo->philo_data_mutex);
}

int	ft_eat(t_philosopher *philo, int id, long time)
{
	int		check_break;

    check_break = 1;
    if (check_all_alive(*philo) < 0)
        return (-1);
    pthread_mutex_lock(philo->left_fork);
    print_routine(*philo, 1, time, id);
    if (check_one_philo(philo) < 1)
        return (-1);
    pthread_mutex_lock(philo->rigth_fork);
    print_routine(*philo, 1, time, id);
    pthread_mutex_lock(philo->philo_data_mutex);
    philo->last_eat = ft_get_time();
    philo->eaten++;
    print_routine(*philo, 2, philo->rules->start_time, philo->id);
    ft_msleep(philo->rules->time_to_eat);
    if (philo->eaten == philo->rules->num_philo_eat)
        check_break = -1;
    pthread_mutex_unlock(philo->philo_data_mutex);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->rigth_fork);
    if (check_break < 0)
        return (-1);
    ft_sleep(philo);
    return (ft_think(philo));
}
