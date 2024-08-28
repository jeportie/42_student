/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:06:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/27 16:03:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"


void	*ft_routine(void *arg)
{
	t_philo	*philo;
	int	current_end; 
	int	current_init;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	
	current_init = mtx_get_int(INIT_MUTEX, INIT_PHILOS);
	mtx_set_int(INIT_MUTEX, &INIT_PHILOS, current_init + 1);

	while (!mtx_get_bool(START_MUTEX, START))
		ft_precise_usleep(10, philo);

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
		if (ft_check_if_dead(philo))
			break ;
		if (mtx_get_int(MEAL_MUTEX, PHILOS_FULL) == NUM_PHILOS)
			break ;
		ft_sleep(philo);
		if (ft_check_if_dead(philo))
			break;
	}

	current_end = mtx_get_int(END_MUTEX, END);
	mtx_set_int(END_MUTEX, &END, current_end + 1);

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

    mtx_set_int(MEAL_MUTEX, &philo->meals_eaten, philo->meals_eaten + 1);

    if (mtx_get_int(MEAL_MUTEX, philo->meals_eaten) == NUM_MEALS)
    {
        current_full = mtx_get_int(MEAL_MUTEX, PHILOS_FULL);
        mtx_set_int(MEAL_MUTEX, &PHILOS_FULL, current_full + 1);
    }

    ft_print_state(philo, EAT);
    ft_precise_usleep(philo->simu->params.time_to_eat * 1000, philo);
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
	ft_precise_usleep(philo->simu->params.time_to_sleep * 1000, philo);
}
