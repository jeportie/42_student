/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:00:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/04 13:27:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * TODO
 * Probleme avec compteur -> des fois fais mourrir un philo avant meme quil
 * pense
 */

#include "include/philo.h"

bool	ft_check_if_dead(t_philo *philo)
{
	long long	time;
	long long	last_meal;

	pthread_mutex_lock(&philo->time_mutex);
	last_meal = philo->last_meal_time;
	pthread_mutex_unlock(&philo->time_mutex);

	pthread_mutex_lock(&philo->mtdata->stop_mutex);
	if (philo->mtdata->stop_flag == true)
		return (true);
	pthread_mutex_unlock(&philo->mtdata->stop_mutex);

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

static bool	ft_mon_routine(t_monitor *mon)
{
	int	i;
	int	wait_philos;

	i = 0;
	while (i < mon->rdonly->num_philo)
	{
		if (ft_check_if_dead(&mon->simu->philos[i]))
			return (false);
		i++;
	}
	pthread_mutex_lock(&mon->mtdata->end_mutex);
	wait_philos = mon->mtdata->end_count;
	pthread_mutex_unlock(&mon->mtdata->end_mutex);

	if (wait_philos	== mon->rdonly->num_philo)
	{
		pthread_mutex_lock(&mon->mtdata->stop_mutex);
		mon->mtdata->stop_flag = true;
		pthread_mutex_unlock(&mon->mtdata->stop_mutex);
		return (false);
	}
	ft_precise_usleep(100);
	return (true);
}

void	*ft_monitor(void *arg)
{
	t_monitor	*mon;

	mon = (t_monitor *)arg;
	if (!mon)
		return (NULL);
	mtx_increment_int(&mon->mtdata->go_mutex, &mon->mtdata->go_count);
	ft_wait_for_start(&mon->mtdata->start_mutex, &mon->mtdata->start_flag);
	ft_precise_usleep(100);
	while (1)
	{
		pthread_mutex_lock(&mon->mtdata->stop_mutex);
		if (mon->mtdata->stop_flag == true)
		{
			pthread_mutex_unlock(&mon->mtdata->stop_mutex);
			break;
		}
		pthread_mutex_unlock(&mon->mtdata->stop_mutex);
		if (!ft_mon_routine(mon))
			break ;
		ft_precise_usleep(100);
	}
	mtx_increment_int(&mon->mtdata->end_mutex, &mon->mtdata->end_count);
	return (NULL);
}
