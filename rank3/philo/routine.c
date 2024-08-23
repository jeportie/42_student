/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:06:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/23 23:15:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*ft_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (!philo)
		return(NULL);
	sleep(1);
	printf("Hello, I am philosopher n.%d.\n", philo->id);
	return (NULL);
}

void		*ft_think(t_philo *philo);
void		*ft_pick_up_forks(t_philo *philo);
void		*ft_eat(t_philo *philo);
void		*ft_sleep(t_philo *philo);
void		*ft_release_forks(t_philo *philo);

/*
 * etat pense = etat de base, dans cette etat, tanter de recup fourchette, si suceces, manger, etc, ... si echec, relever le temps et si ca depasse time to die, stop simu
*/
