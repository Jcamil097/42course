/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:11:56 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/30 12:50:45 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_routine(t_philosopher philo, int m_type, long start_time, int id)
{
	int	all_allive;

	pthread_mutex_lock(philo.all_alive_mutex);
	all_allive = *philo.all_alive;
	pthread_mutex_unlock(philo.all_alive_mutex);
	if (all_allive < 0)
		return ;
	if (m_type == 1)
		printf("[%ld] [%d] \033[1;92mhas taken a fork 🍴\033[0;39m\n",
			ft_get_time() - start_time, id);
	else if (m_type == 2)
		printf("[%ld] [%d] \033[1;94mis eating 🍜\033[0;39m\n", ft_get_time()
			- start_time, id);
	else if (m_type == 3)
		printf("[%ld] [%d] \033[1;89mis sleeping 😴\033[0;39m\n", ft_get_time()
			- start_time, id);
	else if (m_type == 4)
		printf("[%ld] [%d] \033[1;91mis thinking 🙇🏻‍♂️💭\033[0;39m\n",
			ft_get_time() - start_time, id);
}

int	check_all_alive(t_philosopher philo)
{
	int	all_allive;

	pthread_mutex_lock(philo.all_alive_mutex);
	all_allive = *philo.all_alive;
	pthread_mutex_unlock(philo.all_alive_mutex);
	if (all_allive < 0)
		return (-1);
	return (1);
}

int	check_one_philo(t_philosopher *philo)
{
	int	i;

	i = 1;
	if (philo->rules->num_of_philo == 1)
	{
		ft_msleep(philo->rules->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	pthread_mutex_lock(philo->all_alive_mutex);
	if (*philo->all_alive < 0)
		i = -1;
	pthread_mutex_unlock(philo->all_alive_mutex);
	return (i);
}
