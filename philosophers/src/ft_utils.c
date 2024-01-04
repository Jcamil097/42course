/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:47:09 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/04 17:21:48 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(int ms)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(ms / 10);
}

int	check_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_dead(t_philo *philo, int num)
{
	pthread_mutex_lock(&philo->info->mutex_dead);
	if (num == 1)
		philo->info->stop = 1;
	if (philo->info->stop == 1)
	{
		pthread_mutex_unlock(&philo->info->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->mutex_dead);
	return (0);
}

void	print(t_philo *philo, char *str)
{
	long int	time;

	pthread_mutex_lock(&(philo->info->print));
	time = get_time() - philo->info->time_start;
	if (!philo->info->stop && time >= 0 && time <= INT_MAX && !is_dead(philo,
			0))
		printf("\033[1;89m[%lld] [%d] %s", get_time() - philo->info->time_start,
			philo->num, str);
	pthread_mutex_unlock(&(philo->info->print));
}
