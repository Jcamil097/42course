/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:08:05 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/30 12:28:58 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <limits.h>

typedef struct rules_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_philo_eat;
	long			start_time;
	pthread_mutex_t	*forks;
}				t_rules;

typedef struct philo_data
{
	int				id;
	int				eaten;
	int				*all_alive;
	long			last_eat;
	t_rules			*rules;
	pthread_t		thread;
	pthread_t		monitor_thread;
	pthread_mutex_t	*philo_data_mutex;
	pthread_mutex_t	*rigth_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*all_alive_mutex;
	pthread_mutex_t print_mutex;
}				t_philosopher;


/**************libft**************/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**************check_args**************/
int		ft_atoi(const char *str);
void	free_split(char **split);
char	**arg_error_check(char **argv, int i);
void	check_arg_limits(char **argv);

/**************split**************/
char	**ft_split(char const *s, char c);

/**************main**************/
void	exit_and_message(char *message);

/**************main**************/
void	ft_msleep(long wait_ms);
long	ft_get_time(void);

/**************routine**************/
void	*routine(void *arg);
void	*monitor(void *arg);

/**************actions**************/
int		ft_eat(t_philosopher *philo, int id, long time);

/**************routine_utils**************/
void	print_routine(t_philosopher philo, int m_type, long start_time, int id);
int		check_all_alive(t_philosopher philo);
int		check_one_philo(t_philosopher *philo);
int		ft_extended_eat(t_philosopher *philo, int check_break);

#endif