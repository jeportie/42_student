/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:23:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/25 15:40:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h> 
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

# define START_TIME (philo->simu->start_time)
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define RESET   "\033[0m"

typedef struct timeval	t_timeval;
typedef struct s_simu	t_simu;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long long		last_meal_time;
	int				meals_eaten;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_simu			*simu;
}					t_philo;

typedef struct s_params
{
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_meals;
}				t_params;

typedef struct s_simu
{
	t_params		params;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	long long		start_time;
	bool			someone_died;
	pthread_mutex_t death_mutex;
	int				philo_have_eat;
	pthread_mutex_t	meal_mutex;
	int				end;
	pthread_mutex_t	end_mutex;
}				t_simu;

/*Parsing*/
bool		ft_is_int(char *nptr);
bool		ft_check_args(int ac, char **av);

/*Init*/
bool		ft_init_params(t_simu *simu, int ac, char **av);
bool		ft_init_philos(t_simu *simu);
bool		ft_init_forks(t_simu *simu);
bool		ft_init_threads(t_simu *simu);

/*Threads*/
void		*ft_routine(void *arg);
void		ft_think(t_philo *philo);
bool		ft_pick_up_forks(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_release_forks(t_philo *philo);

/*Utilities*/
void		ft_perror(char *str);
long long	ft_get_time_ms(void);

/*Printing*/
void		ft_print_intro(void);
void		ft_print_params(t_params params);
void		ft_print_philos(t_simu simu);
void		ft_print_parsing(t_simu simu);

/*42_ft*/
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_issign(int c, int *sign);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);

#endif /*PHILO_H*/
