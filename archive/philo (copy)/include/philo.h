/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:23:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/28 10:26:16 by jeportie         ###   ########.fr       */
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

# define START_TIME(philo) ((philo)->simu->start_time)
# define NUM_PHILOS (philo->simu->params.num_philo)
# define NUM_MEALS (philo->simu->params.num_meals)

# define DEAD_MUTEX (philo->simu->death_mutex)
# define MEAL_MUTEX (philo->simu->meal_mutex)
# define INIT_MUTEX (philo->simu->init_mutex)
# define START_MUTEX (philo->simu->start_mutex)
# define END_MUTEX (philo->simu->end_mutex)

# define SOMEONE_DIED (philo->simu->someone_died)
# define PHILOS_FULL (philo->simu->philos_full)
# define INIT_PHILOS (philo->simu->init_philos)
# define START (philo->simu->start)
# define END (philo->simu->end)

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define RESET   "\033[0m"

# define DEAD 0
# define THINK 1
# define LEFT 2
# define RIGHT 3
# define EAT 4
# define ULEFT 5
# define URIGHT 6
# define SLEEP 7

typedef struct timeval	t_timeval;
typedef struct s_simu	t_simu;
typedef pthread_mutex_t	t_mtx;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long long		last_meal_time;
	int				meals_eaten;
	t_mtx			*right_fork;
	t_mtx			*left_fork;
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
	t_params	params;
	t_philo		*philos;
	t_mtx		*forks;
	long long	start_time;

	bool		someone_died;
	int			philos_full;
	int			init_philos;
	bool		start;
	int			end;
	t_mtx		death_mutex;
	t_mtx		meal_mutex;
	t_mtx		init_mutex;
	t_mtx		start_mutex;
	t_mtx		end_mutex;
}				t_simu;

/*Parsing*/
bool		ft_is_int(char *nptr);
bool		ft_check_args(int ac, char **av);

/*Init*/
bool		ft_init_simu(t_simu *simu);
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

/*Getters/Setters*/
bool		mtx_get_bool(t_mtx mutex, bool value);
void		mtx_set_bool(t_mtx mutex, bool *dest, bool value);
int			mtx_get_int(t_mtx mutex, int value);
void		mtx_set_int(t_mtx mutex, int *dest, int value);
long long	mtx_get_longlong(t_mtx mutex, long long value);
void		mtx_set_longlong(t_mtx mutex, long long *dest, long long value);

/*Check if dead*/
bool		ft_check_if_dead(t_philo *philo);

/*Utilities*/
void		ft_perror(char *str);
long long	ft_get_time_ms(void);
void		ft_precise_usleep(long long usec, t_philo *philo);
void		ft_free_philos(t_simu *simu);

/*Printing*/
void		ft_print_state(t_philo *philo, int state);
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
