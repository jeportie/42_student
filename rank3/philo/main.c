/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:35:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/19 15:00:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_free_philos(t_simu *simu)
{
	int	i;

	free(simu->philos);
	i = 0;
	while (i < simu->params.num_philo)
	{
		pthread_mutex_destroy(&simu->forks[i]);
		i++;
	}
	free(simu->forks);
}

static void	ft_free_remaining_forks(int i, t_simu *simu)
{
	while (i--)
		pthread_mutex_destroy(&simu->forks[i]);
	free(simu->forks);
}

bool	ft_init_forks(t_simu *simu)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* simu->params.num_philo);
	if (!forks)
	{
		ft_perror("Memory Allocation failed to create t_philo *philos.\n");
		return (false);
	}
	i = 0;
	while (i < simu->params.num_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			ft_perror("Mutex init failed.\n");
			ft_free_remaining_forks(i, simu);
			return (false);
		}
		i++;
	}
	simu->forks = forks;
	return (true);
}

int	main(int ac, char **av)
{
	long long	start_time;
	long long	current_time;
	t_simu		simu;

	memset(&simu, 0, sizeof(simu));
	if (!ft_init_params(&simu, ac, av))
		return (1);
	ft_print_params(simu.params);
	if (!ft_init_philos(&simu))
		return (1);
	if (!ft_init_forks(&simu))
		return (1);
	ft_print_intro();
	start_time = ft_get_time_ms();
	printf("The start time is %lld milliseconds\n", start_time - start_time);
	usleep(23 * 1000);
	current_time = ft_get_time_ms();
	printf("The elapsed time is %lld milliseconds\n", current_time - start_time);
	ft_free_philos(&simu);
	return (0);
}
