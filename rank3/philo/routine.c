/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:06:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/26 21:20:05 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

# define DEAD 0
# define THINK 1
# define LEFT 2
# define RIGHT 3
# define EAT 4
# define ULEFT 5
# define URIGHT 6
# define SLEEP 7

static void ft_print_format(t_philo *philo, long long time, const char *format)
{
	printf("[%lldms]\t %d %s\n", time, philo->id, format);
}

void	ft_print_state(t_philo *philo, int state)
{
	long long time;

	time = ft_get_time_ms() - START_TIME;
	if (state == DEAD)
		printf(RED "[%lldms]\t %d died.\n" RESET, time, philo->id);
	if (state == THINK)
		ft_print_format(philo, time, "is thinking.");
	if (state == LEFT)
		ft_print_format(philo, time, "has taken the left fork.");
	if (state == RIGHT)
		ft_print_format(philo, time, "has taken the right fork.");
	if (state == EAT)
		ft_print_format(philo, time, "is eating.");
	if (state == ULEFT)
		ft_print_format(philo, time, "has released the left fork.");
	if (state == URIGHT)
		ft_print_format(philo, time, "has released the right fork.");
	if (state == SLEEP)
		ft_print_format(philo, time, "is sleeping.");

}

bool	ft_check_if_dead(t_philo *philo)
{
	long long	time;

	time = ft_get_time_ms() - philo->last_meal_time;
	if (philo->simu->someone_died == true)
		return (true);
	if (time >= philo->simu->params.time_to_die)
	{
		pthread_mutex_lock(&philo->simu->death_mutex);
		philo->simu->someone_died = true;
		pthread_mutex_unlock(&philo->simu->death_mutex);
		ft_print_state(philo, DEAD);
		return (true);
	}
	return (false);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	philo->last_meal_time = ft_get_time_ms();
	while (1)
	{
		ft_print_state(philo, THINK);
		if (ft_check_if_dead(philo))
			break ;
		if (!ft_pick_up_forks(philo))
			break ;
		if (ft_check_if_dead(philo))
		{
			ft_release_forks(philo);
			break ;
		}
		ft_eat(philo);
		ft_release_forks(philo);
		if (ft_check_if_dead(philo)
			|| philo->simu->philo_have_eat
			== philo->simu->params.num_philo)
			break ;
		ft_sleep(philo);
		if (ft_check_if_dead(philo))
			break;
	}
	philo->simu->end++;
	return (NULL);
}

bool	ft_pick_up_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_state(philo, LEFT);
		if (ft_check_if_dead(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			return (false);
		}
		pthread_mutex_lock(philo->right_fork);
		ft_print_state(philo, RIGHT);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_state(philo, RIGHT);
		if (ft_check_if_dead(philo))
		{
			pthread_mutex_lock(philo->left_fork);
			return (false);
		}
		pthread_mutex_lock(philo->left_fork);
				ft_print_state(philo, LEFT);
	}
	return (true);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->simu->meal_mutex);
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->simu->params.num_meals)
		philo->simu->philo_have_eat++;
	pthread_mutex_unlock(&philo->simu->meal_mutex);
	ft_print_state(philo, EAT);
	usleep(philo->simu->params.time_to_eat * 1000);
	philo->last_meal_time = ft_get_time_ms();
	if (ft_check_if_dead(philo))
		return ;
}

void		ft_release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		ft_print_state(philo, URIGHT);
		pthread_mutex_unlock(philo->left_fork);
		ft_print_state(philo, ULEFT);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		ft_print_state(philo, ULEFT);
		pthread_mutex_unlock(philo->right_fork);
		ft_print_state(philo, URIGHT);
	}
}

void		ft_sleep(t_philo *philo)
{
	ft_print_state(philo, SLEEP);
	if (ft_check_if_dead(philo))
		return ;
	usleep(philo->simu->params.time_to_sleep * 1000);
}
