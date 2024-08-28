/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:00:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/28 14:08:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * TODO
 * voir comment utiliser ft_check_if_dead dans notre monitor_routine
 */

#include "include/philo.h"

bool	ft_check_if_dead(t_philo *philo)
{
	long long	time;

	if (mtx_get_bool(philo->mtdata->death_mutex, philo->mtdata->someone_died))
		return (true);
	time = ft_get_time_ms() - philo->last_meal_time;
	if (time >= philo->rdonly->time_to_die)
	{
		mtx_set_bool(philo->mtdata->death_mutex, &philo->mtdata->someone_died, true);
		ft_print_state(philo, DEAD);
		return (true);
	}
	return (false);
}

void	*ft_monitor_routine(void *arg)
{
	t_monitor	*mon;

	mon = (t_monitor *)arg;

	return (NULL);
}
