/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:14:23 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/27 12:02:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

bool	ft_check_if_dead(t_philo *philo)
{
	long long	time;

	if (mtx_get_bool(philo->simu->death_mutex, philo->simu->someone_died))
		return (true);
	time = ft_get_time_ms() - philo->last_meal_time;
	if (time >= philo->simu->params.time_to_die)
	{
		mtx_set_bool(philo->simu->death_mutex, &philo->simu->someone_died, true);
		ft_print_state(philo, DEAD);
		return (true);
	}
	return (false);
}
