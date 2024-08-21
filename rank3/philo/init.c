/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:59:42 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/21 21:10:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

bool	ft_init_params(t_simu *simu, int ac, char **av)
{
	t_params	params;

	if (!(ac >= 5 && ac <= 6))
	{
		ft_perror("Wrong format!\n");
		return (false);
	}
	if (!ft_check_args(ac, av))
	{
		ft_perror("Invalid args! Only ints allowed.\n");
		return (false);
	}
	memset(&params, 0, sizeof(params));
	params.num_philo = atoi(av[1]);
	params.time_to_die = atoi(av[2]);
	params.time_to_eat = atoi(av[3]);
	params.time_to_sleep = atoi(av[4]);
	if (ac == 6)
		params.num_meals = atoi(av[5]);
	simu->params = params;
	return (true);
}

bool	ft_init_philos(t_simu *simu)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)malloc(sizeof(t_philo) * simu->params.num_philo);
	if (!philos)
	{
		ft_perror("Memory Allocation failed to create t_philo *philos.\n");
		return (false);
	}
	i = 0;
	while (i < simu->params.num_philo)
	{
		memset(&philos[i], 0, sizeof(t_philo));
		philos[i].id = i + 1;
		philos[i].left_fork = &simu->forks[i];
		philos[i].right_fork = &simu->forks[(i + 1) % simu->params.num_philo];
		i++;
	}
	simu->philos = philos;
	return (true);
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
