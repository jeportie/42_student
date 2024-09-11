/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:08:50 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/11 13:08:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	mtx_increment_int(t_mtx *mutex, int *dest)
{
	pthread_mutex_lock(mutex);
	*dest += 1;
	pthread_mutex_unlock(mutex);
}

void	mtx_set_llong(t_mtx *mutex, long long *dest, long long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

void	ft_wait_for_stop(t_mtx *mutex, bool *start)
{
	pthread_mutex_lock(mutex);
	while ((*start) == true)
	{
		pthread_mutex_unlock(mutex);
		ft_precise_usleep(100);
		pthread_mutex_lock(mutex);
	}
	pthread_mutex_unlock(mutex);
}

bool	ft_check_if_already_finished(t_philo *philo)
{
	pthread_mutex_lock(&philo->finish_mutex);
	if (philo->finish_flag == true)
	{
		pthread_mutex_unlock(&philo->finish_mutex);
		return (false);
	}
	pthread_mutex_unlock(&philo->finish_mutex);
	return (true);
}

bool	ft_check_if_dead(t_philo *philo)
{
	long long	time;
	long long	last_meal;

	if (!ft_check_if_already_finished(philo))
		return (false);
	pthread_mutex_lock(&philo->time_mutex);
	last_meal = philo->last_meal_time;
	pthread_mutex_unlock(&philo->time_mutex);
	pthread_mutex_lock(&philo->mtdata->stop_mutex);
	if (philo->mtdata->stop_flag == true)
		return (true);
	pthread_mutex_unlock(&philo->mtdata->stop_mutex);
	if (ft_get_time_ms() - philo->rdonly->start_time <= 5)
		time = ft_get_time_ms() - philo->rdonly->start_time;
	else
		time = ft_get_time_ms() - last_meal;
	if (time >= philo->rdonly->time_to_die)
	{
		pthread_mutex_lock(&philo->mtdata->stop_mutex);
		philo->mtdata->stop_flag = true;
		pthread_mutex_unlock(&philo->mtdata->stop_mutex);
		ft_print_state(philo, DEAD);
		return (true);
	}
	return (false);
}
