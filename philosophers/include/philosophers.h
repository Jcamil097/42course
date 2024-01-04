/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:50:44 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/04 16:03:12 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct l_philo
{
	int				num;
	int				eat_count;
	int				is_eating;
	long int		last_eat;
	pthread_t		thread;
	pthread_mutex_t	*mut_fork_right;
	pthread_mutex_t	mut_fork_left;
	struct l_info	*info;
}					t_philo;

typedef struct l_info
{
	int				philo_eat;
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				stop;
	long int		time_start;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_dead;
}					t_info;

/*************libft*****************/
int					ft_atoi(const char *str);
int					ft_isdigit(int character);

/*************philo*****************/
int					philo_init(t_info *data);

/*************ft_utils*****************/
long long int		get_time(void);
void				ft_usleep(int ms);
int					check_num(char **str);
int					is_dead(t_philo *philo, int num);
void				print(t_philo *philo, char *str);

/*************philo_utils*****************/
void				take_forks(t_philo *philo);
void				philo_eat(t_philo *philo);
void				*check_death(void *phi);

#endif