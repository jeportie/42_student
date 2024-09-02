/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:00:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/02 13:13:20 by jeportie         ###   ########.fr       */
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
		mtx_set_bool(mon->mtdata->death_mutex, &mon->mtdata->stop, true);
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

	while (!mtx_get_bool(mon->mtdata->death_mutex, mon->mtdata->stop))
	{
		if (!ft_mon_routine(mon))
			break ;
	}
//	ft_stop_threads(mon->simu);
	return (NULL);
}
