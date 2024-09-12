/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:35:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/12 21:50:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	ft_safe_thread_init(t_simu *simu)
{
	if (!ft_init_threads(simu))
	{
		ft_stop_threads(simu);
		ft_free_philos(simu);
		ft_perror("Thread init failed.\n");
		return (false);
	}
	return (true);
}

void	ft_links_init(t_simu *simu)
{
	int	i;

	i = 0;
	while (i < simu->rdonly.num_philo)
	{
		simu->philos[i].left_fork = &simu->forks[i];
		simu->philos[i].right_fork = &simu->forks[(i + 1)
			% simu->rdonly.num_philo];
		simu->forks[i].left_philo = &simu->philos[i];
		simu->forks[i].right_philo = &simu->philos[(i + 1)
			% simu->rdonly.num_philo];
		i++;
	}
}

bool	ft_safe_simulation_init(t_simu *simu, int ac, char **av)
{
	if (!ft_init_mtdata(simu) || !ft_init_rdonly(simu, ac, av))
		return (false);
	if (!ft_init_philos(simu) || !ft_init_forks(simu))
	{
		ft_free_philos(simu);
		return (false);
	}
	ft_links_init(simu);
	ft_init_monitor(simu);
	if (!ft_safe_thread_init(simu))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_simu		simu;

	if (!ft_safe_simulation_init(&simu, ac, av))
		return (-1);
	if (DEBBUG == true)
		ft_print_parsing(simu);
	ft_start_simulation(&simu);
	ft_free_philos(&simu);
	return (0);
}
