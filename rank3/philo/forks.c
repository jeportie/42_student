/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:42:36 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/10 21:00:14 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * NOTE:
 */

#include "include/philo.h"

void	ft_get_time(t_forks *fork, long long *time_left, long long *time_right)
{
	pthread_mutex_lock(&fork->left_philo->time_mutex);
	*time_left = ft_get_time_ms() - fork->left_philo->last_meal_time;
	pthread_mutex_unlock(&fork->left_philo->time_mutex);
	pthread_mutex_lock(&fork->right_philo->time_mutex);
	*time_right = ft_get_time_ms() - fork->right_philo->last_meal_time;
	pthread_mutex_unlock(&fork->right_philo->time_mutex);
}

bool	ft_fork_request(int philo_id, t_forks *fork)
{
	long long	time_left;
	long long	time_right;
	bool		result;

	result = false;
	pthread_mutex_lock(&fork->request_mutex);
	ft_get_time(fork, &time_left, &time_right);
	if (philo_id == fork->left_philo->id)
	{
		if (time_left < time_right)
			result = false;
		else
			result = true;
	}
	else if (philo_id == fork->right_philo->id)
	{
		if (time_left < time_right)
			result = true;
		else
			result = false;
	}
	else
		result = false;
	pthread_mutex_unlock(&fork->request_mutex);
	return (result);
}

void	ft_define_forks(t_philo *philo, t_forks **fone,
		t_forks **ftwo, bool state)
{
	if (state == EVEN)
	{
		*fone = philo->left_fork;
		*ftwo = philo->right_fork;
	}
	else
	{
		*fone = philo->right_fork;
		*ftwo = philo->left_fork;
	}
}

void	ft_actualise_forks(t_forks *fork, bool value, int id)
{
	pthread_mutex_lock(&fork->lock_mutex);
	fork->is_locked = value;
	fork->philo_id = id;
	pthread_mutex_unlock(&fork->lock_mutex);
}

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

	//NOTE: verifier si cest ok de cal l'adresse du pointeur et si 
	//cest pas ca qui fou la merde.
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
