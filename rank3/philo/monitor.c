/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:00:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/03 12:20:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * TODO
 */

#include "include/philo.h"

bool	ft_check_if_dead(t_philo *philo)
{
	long long	time;
	long long	last_meal;

	last_meal = mtx_get_llong(philo->mtdata->init_mutex, philo->last_meal_time);
	if (mtx_get_bool(philo->mtdata->death_mutex, philo->mtdata->stop))
		return (true);
	time = ft_get_time_ms() - last_meal;
	if (time >= philo->rdonly->time_to_die)
	{
		mtx_set_bool(philo->mtdata->death_mutex, &philo->mtdata->stop, true);
		ft_print_state(philo, DEAD);
		return (true);
	}
	return (false);
}

static bool	ft_mon_routine(t_monitor *mon)
{
	int	i;

	i = 0;
	while (i < mon->rdonly->num_philo)
	{
		if (ft_check_if_dead(&mon->simu->philos[i]))
			return (false);
		i++;
	}
	if (mtx_get_int(mon->mtdata->end_mutex, mon->mtdata->end_philos)
		== mon->rdonly->num_philo)
	{
		pthread_mutex_lock(&mon->mtdata->death_mutex);
		mon->mtdata->stop = true;
		pthread_mutex_unlock(&mon->mtdata->death_mutex);
		return (false);
	}
	ft_precise_usleep(100, mon->simu);
	return (true);
}

void	*ft_monitor(void *arg)
{
	t_monitor	*mon;

	mon = (t_monitor *)arg;
	if (!mon)
		return (NULL);
	mtx_increment_int(&mon->mtdata->init_mutex, &mon->mtdata->init_philos);
	ft_wait_for_start(mon->simu, &mon->mtdata->start_mutex, &mon->mtdata->start);
	ft_precise_usleep(1000, mon->simu);
	while (1)
	{
		pthread_mutex_lock(&mon->mtdata->death_mutex);
		if (mon->mtdata->stop == true)
		{
			pthread_mutex_unlock(&mon->mtdata->death_mutex);
			break;
		}
		pthread_mutex_unlock(&mon->mtdata->death_mutex);
		if (!ft_mon_routine(mon))
			break ;
		ft_precise_usleep(1000, mon->simu);
	}
	mtx_increment_int(&mon->mtdata->end_mutex, &mon->mtdata->end_philos);
	return (NULL);
}
