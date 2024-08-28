/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:35:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/27 19:57:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char **av)
{
	t_simu		simu;

	if (!ft_init_simu(&simu))
		return (1);
	printf(GREEN "[0ms]\t Simulation Starts.\n" RESET);
	if (!ft_init_params(&simu, ac, av) || !ft_init_forks(&simu)
		|| !ft_init_philos(&simu) || !ft_init_threads(&simu))
	{
		ft_free_philos(&simu);
		return (1);
	}

	while (mtx_get_int(simu.init_mutex, simu.init_philos) != simu.params.num_philo)
		usleep(10);
	simu.start_time = ft_get_time_ms();
	mtx_set_bool(simu.start_mutex, &simu.start, true);

	while (mtx_get_int(simu.end_mutex, simu.end) != simu.params.num_philo)
		usleep(10);

	printf(GREEN "[%lldms]\t Simulation Ended.\n\n" RESET,
		ft_get_time_ms() - simu.start_time);
	ft_free_philos(&simu);
	return (0);
}
