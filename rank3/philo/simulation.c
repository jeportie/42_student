/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:51:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/06 14:41:14 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
 * NOTE: THIS IS THE MASTER THRED
 */

static void	ft_wait_threads_to_start(t_simu *simu)
{
	pthread_mutex_lock(&simu->mtdata.go_mutex);
	while (simu->mtdata.go_count != simu->rdonly.num_philo + 1)
	{
		pthread_mutex_unlock(&simu->mtdata.go_mutex);
		ft_precise_usleep(100);
		pthread_mutex_lock(&simu->mtdata.go_mutex);
	}
	pthread_mutex_unlock(&simu->mtdata.go_mutex);
}

void	ft_wait_threads_to_stop(t_simu *simu)

{
	pthread_mutex_lock(&simu->mtdata.stop_mutex);
	while (simu->mtdata.stop_flag == false)
	{
		pthread_mutex_unlock(&simu->mtdata.stop_mutex);
		ft_precise_usleep(100);
		pthread_mutex_lock(&simu->mtdata.stop_mutex);
	}
	pthread_mutex_unlock(&simu->mtdata.stop_mutex);
}

void	ft_start_simulation(t_simu *simu)
{
	ft_wait_threads_to_start(simu);
	if (DEBBUG == true)
		ft_print_start_stop(simu, true);
	pthread_mutex_lock(&simu->mtdata.start_mutex);
	simu->mtdata.start_flag = true;
	simu->rdonly.start_time = ft_get_time_ms();
	pthread_mutex_unlock(&simu->mtdata.start_mutex);
	ft_wait_threads_to_stop(simu);
	ft_stop_threads(simu);
	pthread_mutex_lock(&simu->mtdata.start_mutex);
	simu->mtdata.start_flag = false;
	pthread_mutex_unlock(&simu->mtdata.start_mutex);
	if (simu->monitor.thread)
		pthread_join(simu->monitor.thread, NULL);
	if (DEBBUG == true)
		ft_print_start_stop(simu, false);
}
