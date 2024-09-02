/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:51:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/02 13:15:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
 * NOTE: THIS IS THE MASTER THRED
 */

bool	ft_start_simulation(t_simu *simu)
{
	if (!ft_init_threads(simu))
	{
		ft_stop_threads(simu);
		ft_free_philos(simu);
		return (false);
	}

	pthread_mutex_lock(&simu->mtdata.init_mutex);
	while (simu->mtdata.init_philos != simu->rdonly.num_philo + 1)
	{
		pthread_mutex_unlock(&simu->mtdata.init_mutex);
		ft_precise_usleep(1000, simu);
		pthread_mutex_lock(&simu->mtdata.init_mutex);
	}
	pthread_mutex_unlock(&simu->mtdata.init_mutex); 

	ft_precise_usleep(1000, simu);
	ft_print_start_stop(simu, true);
	simu->rdonly.start_time = ft_get_time_ms();
	mtx_set_bool(simu->mtdata.start_mutex, &simu->mtdata.start, true);
	ft_precise_usleep(1000, simu);

	while (1)
	{
		pthread_mutex_lock(&simu->mtdata.death_mutex);
		if (simu->mtdata.stop == true)
		{
			pthread_mutex_unlock(&simu->mtdata.death_mutex);
			break ;
		}
		pthread_mutex_unlock(&simu->mtdata.death_mutex);
		ft_precise_usleep(100, simu);
	}
	ft_stop_threads(simu);
	return (true);
}
