/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:02:44 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/11 13:05:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
