/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:35:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/23 23:16:58 by jeportie         ###   ########.fr       */
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
}

int	main(int ac, char **av)
{
	long long	start_time;
	long long	current_time;
	t_simu		simu;

	start_time = ft_get_time_ms();
	printf("The start time is %lld milliseconds\n", start_time - start_time);
	ft_print_intro();
	memset(&simu, 0, sizeof(simu));
	if (!ft_init_params(&simu, ac, av) || !ft_init_forks(&simu)
		|| !ft_init_philos(&simu))
	{
		ft_free_philos(&simu);
		return (1);
	}
	ft_print_parsing(simu);
	if (!ft_init_threads(&simu))
	{
		ft_free_philos(&simu);
		return (1);
	}

	ft_free_philos(&simu);
//	usleep(23 * 1000);
	current_time = ft_get_time_ms();
	printf("The elapsed time is %lld milliseconds\n", current_time - start_time);
	return (0);
}
