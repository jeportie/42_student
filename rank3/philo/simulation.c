/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:51:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/03 12:07:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
 * NOTE: THIS IS THE MASTER THRED
 */

static void	ft_wait_threads_to_start(t_simu *simu)
{
	pthread_mutex_lock(&simu->mtdata.init_mutex);
	while (simu->mtdata.init_philos != simu->rdonly.num_philo + 1)
	{
		pthread_mutex_unlock(&simu->mtdata.init_mutex);
		ft_precise_usleep(100, simu);
		pthread_mutex_lock(&simu->mtdata.init_mutex);
	}
	pthread_mutex_unlock(&simu->mtdata.init_mutex);
}

static void	ft_wait_threads_to_stop(t_simu *simu)

{
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
}

void	ft_start_simulation(t_simu *simu)
{
	ft_wait_threads_to_start(simu);
	simu->rdonly.start_time = ft_get_time_ms();
	ft_print_start_stop(simu, true);

	pthread_mutex_lock(&simu->mtdata.start_mutex);
	simu->mtdata.start = true;
	pthread_mutex_unlock(&simu->mtdata.start_mutex);

	ft_wait_threads_to_stop(simu);
	ft_stop_threads(simu);
}
