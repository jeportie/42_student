/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:35:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/29 12:52:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
 * TODO
 * Implementer monitor pour voir quand philo meurt
 * Regler pb de freeze qui arrive avant que la simu commemce
 * Trouver moyen de laisser lock printf apres que someonedied (peut etre en coupant la simu puis en printant)
 */ 

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
	ft_start_simulation(&simu);

	ft_print_start_stop(&simu, false);
	ft_free_philos(&simu);
	return (0);
}
