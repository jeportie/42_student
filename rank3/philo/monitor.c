/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:00:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/11 13:11:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static bool	ft_mon_routine(t_monitor *mon)
{
	int	i;
	int	wait_philos;

	i = 0;
	mtx_increment_int(&mon->mtdata->go_mutex, &mon->mtdata->go_count);
	ft_wait_for_start(&mon->mtdata->start_mutex, &mon->mtdata->start_flag);
	while (i < mon->rdonly->num_philo)
	{
		if (ft_check_if_dead(&mon->simu->philos[i]))
			return (false);
		i++;
	}
	pthread_mutex_lock(&mon->mtdata->end_mutex);
	wait_philos = mon->mtdata->end_count;
	pthread_mutex_unlock(&mon->mtdata->end_mutex);
	if (wait_philos == mon->rdonly->num_philo)
	{
		pthread_mutex_lock(&mon->mtdata->stop_mutex);
		mon->mtdata->stop_flag = true;
		pthread_mutex_unlock(&mon->mtdata->stop_mutex);
		return (false);
	}
	ft_precise_usleep(100);
	return (true);
}

bool	ft_check_end(t_monitor *mon)
{
	pthread_mutex_lock(&mon->mtdata->stop_mutex);
	if (mon->mtdata->stop_flag == true)
	{
		pthread_mutex_unlock(&mon->mtdata->stop_mutex);
		return (false);
	}
	pthread_mutex_unlock(&mon->mtdata->stop_mutex);
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
	while (1)
	{
		if (!ft_check_end(mon))
			break ;
		if (!ft_mon_routine(mon))
			break ;
	}
	mtx_increment_int(&mon->mtdata->end_mutex, &mon->mtdata->end_count);
	ft_wait_threads_to_stop(mon->simu);
	if (mon->rdonly->num_philo > 1)
		ft_wait_for_stop(&mon->mtdata->start_mutex, &mon->mtdata->start_flag);
	if (mon->mtdata->print_mutex.is_locked == true)
		pthread_mutex_unlock(&mon->mtdata->print_mutex.pmutex);
	return (NULL);
}
