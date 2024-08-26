/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:35:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/26 17:30:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_free_philos(t_simu *simu)
{
	int	i;

	if (simu->philos)
	{
		i = 0;
		while (i < simu->params.num_philo)
		{
			if (simu->philos[i].thread)
				pthread_join(simu->philos[i].thread, NULL);
			i++;
		}
	}
	if (simu->forks)
	{
		i = 0;
		while (i < simu->params.num_philo)
		{
			pthread_mutex_destroy(&simu->forks[i]);
			i++;
		}
	}
	if (simu->philos)
		free(simu->philos);
	if (simu->forks)
		free(simu->forks);
	pthread_mutex_destroy(&simu->death_mutex);
	pthread_mutex_destroy(&simu->meal_mutex);
	pthread_mutex_destroy(&simu->death_mutex);
}


int	main(int ac, char **av)
{
	t_simu		simu;

	memset(&simu, 0, sizeof(simu));
	if (pthread_mutex_init(&simu.death_mutex, NULL) != 0)
	{
		ft_perror("Mutex init failed.\n");
		ft_free_philos(&simu);	
	}
	if (pthread_mutex_init(&simu.meal_mutex, NULL) != 0)
	{
		ft_perror("Mutex init failed.\n");
		ft_free_philos(&simu);	
	}
	if (pthread_mutex_init(&simu.end_mutex, NULL) != 0)
	{
		ft_perror("Mutex init failed.\n");
		ft_free_philos(&simu);	
	}
	printf(GREEN "[0ms]\t Simulation Starts.\n" RESET);
	if (!ft_init_params(&simu, ac, av) || !ft_init_forks(&simu)
		|| !ft_init_philos(&simu) || !ft_init_threads(&simu))
	{
		ft_free_philos(&simu);
		return (1);
	}
	while (simu.end != simu.params.num_philo)
		usleep(100);
	printf(GREEN "[%lldms]\t Simulation Ended.\n\n" RESET, ft_get_time_ms() - simu.start_time);

	ft_free_philos(&simu);
	return (0);
}
