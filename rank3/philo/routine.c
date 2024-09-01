/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:06:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/01 19:49:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void ft_wait_for_start(t_mtx *mutex, bool *start)
{
    pthread_mutex_lock(mutex);
    while (!(*start)) 
	{
        pthread_mutex_unlock(mutex);  // Allow other threads to acquire the lock
        usleep(1000);                 // Sleep briefly
        pthread_mutex_lock(mutex);    // Re-lock to check the condition again
    }
    pthread_mutex_unlock(mutex);
}


void	*ft_routine(void *arg)
{
	t_philo	*philo;
	int		current_end;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);

	philo->last_meal_time = ft_get_time_ms();

	mtx_increment_int(&philo->mtdata->init_mutex, &philo->mtdata->init_philos);
	ft_wait_for_start(&philo->mtdata->start_mutex, &philo->mtdata->start);

	while (1)
	{
		if (ft_check_if_dead(philo))
			break;
		ft_print_state(philo, THINK);
		ft_pick_up_forks(philo);
		ft_eat(philo);
		ft_release_forks(philo);
		if (philo->meals_eaten == philo->rdonly->num_meals)
			break;
		ft_sleep(philo);
	}
	current_end = mtx_get_int(philo->mtdata->end_mutex, philo->mtdata->end_philos);
	mtx_set_int(philo->mtdata->end_mutex, &philo->mtdata->end_philos, current_end + 1);
//	ft_print_state(philo, STOP);
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
			pthread_mutex_unlock(philo->left_fork);
			return (false);
		}
		pthread_mutex_lock(philo->left_fork);
		ft_print_state(philo, LEFT);
	}
	return (true);
}

void	ft_eat(t_philo *philo)
{
	int	current_full;

	ft_precise_usleep(philo->rdonly->time_to_eat * 1000, philo->simu);
	mtx_set_longlong(philo->mtdata->init_mutex, &philo->last_meal_time, ft_get_time_ms());
	mtx_set_int(philo->mtdata->meal_mutex, &philo->meals_eaten, philo->meals_eaten + 1);
	if (mtx_get_int(philo->mtdata->meal_mutex, philo->meals_eaten) == philo->rdonly->num_meals)
	{
		current_full = mtx_get_int(philo->mtdata->meal_mutex, philo->mtdata->philos_full);
		mtx_set_int(philo->mtdata->meal_mutex, &philo->mtdata->philos_full, current_full + 1);
	}

	ft_print_state(philo, EAT);
}

void		ft_release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void		ft_sleep(t_philo *philo)
{
	ft_print_state(philo, SLEEP);
	ft_precise_usleep(philo->rdonly->time_to_sleep * 1000, philo->simu);
}
