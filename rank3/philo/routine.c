/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:06:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/06 14:34:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * TODO:
 * Ajouter fairness system ou autre opti pour passer les tests de la correction
 */

#include "include/philo.h"

void	ft_check_remaining_locks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->lock_mutex);
	if (philo->left_fork->is_locked == true
		&& philo->left_fork->philo_id == philo->id)
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	pthread_mutex_unlock(&philo->left_fork->lock_mutex);
	pthread_mutex_lock(&philo->right_fork->lock_mutex);
	if (philo->right_fork->is_locked == true
		&& philo->right_fork->philo_id == philo->id)
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	pthread_mutex_unlock(&philo->right_fork->lock_mutex);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	bool	dead_flag;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	mtx_increment_int(&philo->mtdata->go_mutex, &philo->mtdata->go_count);
	ft_wait_for_start(&philo->mtdata->start_mutex, &philo->mtdata->start_flag);
	mtx_set_llong(&philo->time_mutex, &philo->last_meal_time, ft_get_time_ms());
	while (1)
	{
		pthread_mutex_lock(&philo->mtdata->stop_mutex);
		dead_flag = philo->mtdata->stop_flag;
		pthread_mutex_unlock(&philo->mtdata->stop_mutex);
		if (dead_flag == true)
			break ;
		ft_print_state(philo, THINK);
		ft_eat(philo);
		if (philo->meals_eaten == philo->rdonly->num_meals)
			break ;
		ft_sleep(philo);
	}
	ft_check_remaining_locks(philo);
	mtx_increment_int(&philo->mtdata->end_mutex, &philo->mtdata->end_count);
	if (DEBBUG == true)
		ft_print_state(philo, STOP);
	return (NULL);
}

void	ft_even_pick(t_philo *philo, bool dead_flag)
{
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	ft_print_state(philo, LEFT);
	pthread_mutex_lock(&philo->left_fork->lock_mutex);
	philo->left_fork->is_locked = true;
	philo->left_fork->philo_id = philo->id;
	pthread_mutex_unlock(&philo->left_fork->lock_mutex);
	pthread_mutex_lock(&philo->mtdata->stop_mutex);
	dead_flag = philo->mtdata->stop_flag;
	pthread_mutex_unlock(&philo->mtdata->stop_mutex);
	if (dead_flag)
	{
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		pthread_mutex_lock(&philo->left_fork->lock_mutex);
		philo->left_fork->is_locked = false;
		philo->left_fork->philo_id = 0;
		pthread_mutex_unlock(&philo->left_fork->lock_mutex);
		return ;
	}
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	ft_print_state(philo, RIGHT);
	pthread_mutex_lock(&philo->right_fork->lock_mutex);
	philo->right_fork->is_locked = true;
	philo->right_fork->philo_id = philo->id;
	pthread_mutex_unlock(&philo->right_fork->lock_mutex);
}

void	ft_odd_pick(t_philo *philo, bool dead_flag)
{
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	ft_print_state(philo, RIGHT);
	pthread_mutex_lock(&philo->right_fork->lock_mutex);
	philo->right_fork->is_locked = true;
	philo->right_fork->philo_id = philo->id;
	pthread_mutex_unlock(&philo->right_fork->lock_mutex);
	pthread_mutex_lock(&philo->mtdata->stop_mutex);
	dead_flag = philo->mtdata->stop_flag;
	pthread_mutex_unlock(&philo->mtdata->stop_mutex);
	if (dead_flag)
	{
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
		pthread_mutex_lock(&philo->right_fork->lock_mutex);
		philo->right_fork->is_locked = false;
		philo->right_fork->philo_id = 0;
		pthread_mutex_unlock(&philo->right_fork->lock_mutex);
		return ;
	}
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	ft_print_state(philo, LEFT);
	pthread_mutex_lock(&philo->left_fork->lock_mutex);
	philo->left_fork->is_locked = true;
	philo->left_fork->philo_id = philo->id;
	pthread_mutex_unlock(&philo->left_fork->lock_mutex);
}

bool	ft_pick_up_forks(t_philo *philo)
{
	bool	dead_flag;

	pthread_mutex_lock(&philo->mtdata->stop_mutex);
	dead_flag = philo->mtdata->stop_flag;
	pthread_mutex_unlock(&philo->mtdata->stop_mutex);
	if (dead_flag)
		return (false);
	if (philo->id % 2 == 0)
		ft_even_pick(philo, dead_flag);
	else
		ft_odd_pick(philo, dead_flag);
	return (true);
}

void	ft_eat(t_philo *philo)
{
	t_mtx	*meal_mtx;

	meal_mtx = &philo->mtdata->meal_mutex;
	ft_pick_up_forks(philo);
	pthread_mutex_lock(&philo->time_mutex);
	philo->last_meal_time = ft_get_time_ms();
	pthread_mutex_unlock(&philo->time_mutex);
	ft_print_state(philo, EAT);
	philo->meals_eaten++;
	ft_precise_usleep(philo->rdonly->time_to_eat * 1000);
	if (philo->meals_eaten == philo->rdonly->num_meals)
		mtx_increment_int(meal_mtx, &philo->mtdata->philos_full);
	ft_release_forks(philo);
}

void	ft_even_release(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->lock_mutex);
	if (philo->right_fork->is_locked == true && philo->right_fork->philo_id == philo->id)
	{
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
		philo->right_fork->is_locked = false;
	}
	pthread_mutex_unlock(&philo->right_fork->lock_mutex);
	pthread_mutex_lock(&philo->left_fork->lock_mutex);
	if (philo->left_fork->is_locked == true && philo->left_fork->philo_id == philo->id)
	{
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		philo->left_fork->is_locked = false;
	}
	pthread_mutex_unlock(&philo->left_fork->lock_mutex);
}

void	ft_odd_release(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->lock_mutex);
	if (philo->left_fork->is_locked == true && philo->left_fork->philo_id == philo->id)
	{
		philo->left_fork->is_locked = false;
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	}
	pthread_mutex_unlock(&philo->left_fork->lock_mutex);
	pthread_mutex_lock(&philo->right_fork->lock_mutex);
	if (philo->right_fork->is_locked == true && philo->right_fork->philo_id == philo->id)
	{
		philo->right_fork->is_locked = false;
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	}
	pthread_mutex_unlock(&philo->right_fork->lock_mutex);
}

void	ft_release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_even_release(philo);
	else
		ft_odd_release(philo);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_state(philo, SLEEP);
	ft_precise_usleep(philo->rdonly->time_to_sleep * 1000);
}
