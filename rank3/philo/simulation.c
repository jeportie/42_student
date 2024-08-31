/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:51:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/30 13:26:16 by jeportie         ###   ########.fr       */
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
	ft_print_start_stop(simu, true);

	while (mtx_get_int(simu->mtdata.init_mutex, simu->mtdata.init_philos)
		!= simu->rdonly.num_philo + 1)
		usleep(100);

	simu->rdonly.start_time = ft_get_time_ms();
	mtx_set_bool(simu->mtdata.start_mutex, &simu->mtdata.start, true);

	while (mtx_get_int(simu->mtdata.end_mutex, simu->mtdata.end) != simu->rdonly.num_philo
			|| mtx_get_bool(simu->mtdata.death_mutex, simu->mtdata.someone_died) == false)
	{
		usleep(10000);
		printf("stuck...");
	}

	if(mtx_get_bool(simu->mtdata.death_mutex, simu->mtdata.someone_died) == false)
		ft_stop_threads(simu);
	printf("return ok\n");
	return (true);
}
