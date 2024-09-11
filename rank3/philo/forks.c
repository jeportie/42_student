/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:42:36 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/11 13:05:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * NOTE:
 */

#include "include/philo.h"

void	ft_picking_order(t_forks *fork, int id)
{
	if (ft_fork_request(id, fork) == true)
		pthread_mutex_lock(&fork->fork_mutex);
	else
	{
		ft_precise_usleep(100);
		pthread_mutex_lock(&fork->fork_mutex);
	}
}

void	ft_fork_pick(t_philo *philo, bool state)
{
	bool	dead_flag;
	t_forks	*fone;
	t_forks	*ftwo;

	ft_define_forks(philo, &fone, &ftwo, state);
	ft_picking_order(fone, philo->id);
	ft_print_state(philo, LEFT);
	ft_actualise_forks(fone, true, philo->id);
	pthread_mutex_lock(&philo->mtdata->stop_mutex);
	dead_flag = philo->mtdata->stop_flag;
	pthread_mutex_unlock(&philo->mtdata->stop_mutex);
	if (dead_flag)
	{
		pthread_mutex_unlock(&fone->fork_mutex);
		ft_actualise_forks(fone, false, 0);
		return ;
	}
	ft_picking_order(ftwo, philo->id);
	ft_print_state(philo, RIGHT);
	ft_actualise_forks(ftwo, true, philo->id);
}

void	ft_release(t_philo *philo, bool state)
{
	t_forks	*fone;
	t_forks	*ftwo;

	ft_define_forks(philo, &fone, &ftwo, state);
	pthread_mutex_lock(&ftwo->lock_mutex);
	if (ftwo->is_locked == true
		&& ftwo->philo_id == philo->id)
	{
		pthread_mutex_unlock(&ftwo->fork_mutex);
		ftwo->is_locked = false;
	}
	pthread_mutex_unlock(&ftwo->lock_mutex);
	pthread_mutex_lock(&fone->lock_mutex);
	if (fone->is_locked == true
		&& fone->philo_id == philo->id)
	{
		fone->is_locked = false;
		pthread_mutex_unlock(&fone->fork_mutex);
	}
	pthread_mutex_unlock(&fone->lock_mutex);
}
