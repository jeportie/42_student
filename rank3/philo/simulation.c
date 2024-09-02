/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:51:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/02 11:20:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_stop_threads(t_simu *simu)
{
	int	i;

	if (simu->philos)
	{
		i = 0;
		while (i < simu->rdonly.num_philo)
		{
			if (simu->philos[i].thread)
				pthread_join(simu->philos[i].thread, NULL);
			i++;
		}
	}
	if (simu->monitor.thread)
		pthread_join(simu->monitor.thread, NULL);
}

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
		usleep(1000);
		pthread_mutex_lock(&simu->mtdata.init_mutex);
	}
	pthread_mutex_unlock(&simu->mtdata.init_mutex); 

	ft_print_start_stop(simu, true);
	simu->rdonly.start_time = ft_get_time_ms();
	mtx_set_bool(simu->mtdata.start_mutex, &simu->mtdata.start, true);

	while (1)
	{
		pthread_mutex_lock(&simu->mtdata.death_mutex);
		if (simu->mtdata.stop == true)
		{
			pthread_mutex_unlock(&simu->mtdata.death_mutex);
			break ;
		}
		pthread_mutex_unlock(&simu->mtdata.death_mutex);
		usleep(100);
	}
	return (true);
}
