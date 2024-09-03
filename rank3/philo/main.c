/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:35:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/03 09:02:15 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
 * TODO
 * Implementer monitor pour voir quand philo meurt
 * Regler pb de freeze qui arrive avant que la simu commemce
 * Trouver moyen de laisser lock printf apres que someonedied 
 * (peut etre en coupant la simu puis en printant)
 */

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

int	main(int ac, char **av)
{
	t_simu		simu;

	if (!ft_init_mtdata(&simu))
		return (1);
	if (!ft_init_rdonly(&simu, ac, av) || !ft_init_forks(&simu)
		|| !ft_init_philos(&simu))
	{
		ft_free_philos(&simu);
		return (1);
	}
	ft_init_monitor(&simu);
	if (!ft_safe_thread_init(&simu))
		return (1);

	ft_start_simulation(&simu);
	ft_print_start_stop(&simu, false);
	ft_free_philos(&simu);
	return (0);
}
