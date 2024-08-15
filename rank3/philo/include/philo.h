/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:23:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/15 16:23:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

typedef struct timeval	t_timeval;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long long		last_meal_time;
	int				meals_eaten;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}					t_philo;

typedef struct s_params
{
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_meals;
	bool	someone_died;
}				t_params;

typedef struct s_simu
{
	t_params	*params;
	t_philo		*philosophers;
	long long	start_time;
}				t_simu;

/*Parsing*/
int		ft_atoi(const char *nptr);
bool	ft_is_int(char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_issign(int c, int *sign);
int		ft_isdigit(int c);
int		ft_isspace(int c);
