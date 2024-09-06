/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:59:42 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/06 11:32:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

bool	ft_init_mtdata(t_simu *simu)
{
	t_sync	mtdata;

	memset(&mtdata, 0, sizeof(mtdata));
	if (pthread_mutex_init(&mtdata.start_mutex, NULL) != 0
		||pthread_mutex_init(&mtdata.print_mutex.pmutex, NULL) != 0
		||pthread_mutex_init(&mtdata.go_mutex, NULL) != 0
		||pthread_mutex_init(&mtdata.stop_mutex, NULL) != 0
		|| pthread_mutex_init(&mtdata.meal_mutex, NULL) != 0
		|| pthread_mutex_init(&mtdata.end_mutex, NULL) != 0)
	{
		simu->mtdata = mtdata;
		ft_perror("Mutex init failed.\n");
		return (false);
	}
	mtdata.print_mutex.is_locked = false;
	simu->mtdata = mtdata;
	return (true);
}

bool	ft_init_rdonly(t_simu *simu, int ac, char **av)
{
	t_rdonly	params;

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
	params.num_philo = ft_atoi(av[1]);
	params.time_to_die = ft_atoi(av[2]);
	params.time_to_eat = ft_atoi(av[3]);
	params.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		params.num_meals = ft_atoi(av[5]);
	simu->rdonly = params;
	return (true);
}

bool	ft_init_philos(t_simu *simu)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)malloc(sizeof(t_philo) * simu->rdonly.num_philo);
	if (!philos)
	{
		ft_perror("Memory Allocation failed to create forks*.\n");
		return (false);
	}
	i = 0;
	while (i < simu->rdonly.num_philo)
	{
		memset(&philos[i], 0, sizeof(t_philo));
		if (pthread_mutex_init(&philos->time_mutex, NULL) != 0)
		{
			ft_perror("Mutex init failed.\n");
			return (false);
		}
		philos[i].id = i + 1;
		philos[i].left_fork = &simu->forks[i];
		philos[i].right_fork = &simu->forks[(i + 1) % simu->rdonly.num_philo];
		philos[i].rdonly = &simu->rdonly;
		philos[i].mtdata = &simu->mtdata;
		philos[i].simu = simu;
		i++;
	}
	simu->philos = philos;
	return (true);
}

void	ft_init_monitor(t_simu *simu)
{
	t_monitor	mon;

	memset(&mon, 0, sizeof(t_monitor));
	mon.rdonly = &simu->rdonly;
	mon.mtdata = &simu->mtdata;
	mon.simu = simu;
	simu->monitor = mon;
}

static void	ft_free_remaining_forks(int i, t_simu *simu)
{
	while (i--)
		pthread_mutex_destroy(&simu->forks[i].fork_mutex);
	free(simu->forks);
}

bool	ft_init_forks(t_simu *simu)
{
	int		i;
	t_forks	*forks;

	forks = (t_forks *)malloc(sizeof(t_forks) * simu->rdonly.num_philo);
	if (!forks)
	{
		ft_perror("Memory Allocation failed to create t_philo *philos.\n");
		return (false);
	}
	i = 0;
	while (i < simu->rdonly.num_philo)
	{
		forks[i].is_locked = false;
		forks[i].philo_id = 0;
		if (pthread_mutex_init(&forks[i].fork_mutex, NULL) != 0
			|| pthread_mutex_init(&forks[i].lock_mutex, NULL) != 0)
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

static void	ft_join_remaining_threads(int i, t_simu *simu)
{
	while (i)
	{
		pthread_join(simu->philos[i].thread, NULL);
		i--;
	}
}

bool	ft_init_threads(t_simu *simu)
{
	int	i;

	i = 0;
	while (i < simu->rdonly.num_philo)
	{
		if (pthread_create(&simu->philos[i].thread, NULL, ft_routine,
				&simu->philos[i]) != 0)
		{
			ft_perror("Thread creation failed.\n");
			ft_join_remaining_threads(i, simu);
			return (false);
		}
		i++;
	}
	if (pthread_create(&simu->monitor.thread, NULL, ft_monitor, &simu->monitor)
		!= 0)
	{
		ft_perror("Thread creation failed.\n");
		ft_join_remaining_threads(i, simu);
		pthread_join(simu->monitor.thread, NULL);
		return (false);
	}
	return (true);
}
