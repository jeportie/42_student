/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:51:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/03 14:15:44 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
 * NOTE: THIS IS THE MASTER THRED
 */

static void	ft_wait_threads_to_start(t_simu *simu)
{
	pthread_mutex_lock(&simu->mtdata.wait_mutex);
	while (simu->mtdata.wait_flag != simu->rdonly.num_philo + 1)
	{
		pthread_mutex_unlock(&simu->mtdata.wait_mutex);
		ft_precise_usleep(100);
		pthread_mutex_lock(&simu->mtdata.wait_mutex);
	}
	simu->mtdata.wait_flag = 0;
	pthread_mutex_unlock(&simu->mtdata.wait_mutex);
}

static void	ft_wait_threads_to_stop(t_simu *simu)

{
	while (1)
	{
		pthread_mutex_lock(&simu->mtdata.action_mutex);
		if (simu->mtdata.action_flag == true)
		{
			simu->mtdata.action_flag = false;
			pthread_mutex_unlock(&simu->mtdata.action_mutex);
			break ;
		}
		pthread_mutex_unlock(&simu->mtdata.action_mutex);
		ft_precise_usleep(100);
	}
}

void	ft_start_simulation(t_simu *simu)
{
	ft_wait_threads_to_start(simu);
	simu->rdonly.start_time = ft_get_time_ms();
	ft_print_start_stop(simu, true);

	printf("Mutex unlocked.");
	pthread_mutex_lock(&simu->mtdata.action_mutex);
	simu->mtdata.action_flag = true;
	pthread_mutex_unlock(&simu->mtdata.action_mutex);

	ft_wait_threads_to_stop(simu);
	ft_stop_threads(simu);
}
