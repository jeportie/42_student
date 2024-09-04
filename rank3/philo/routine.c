/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:06:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/04 14:06:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_wait_for_start(t_mtx *mutex, bool *start)
{
	pthread_mutex_lock(mutex);
	while (!(*start))
	{
		pthread_mutex_unlock(mutex);
		ft_precise_usleep(100);
		pthread_mutex_lock(mutex);
	}
	pthread_mutex_unlock(mutex);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	bool	dead_flag;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);

	mtx_increment_int(&philo->mtdata->init_mutex, &philo->mtdata->init_philos);
	ft_wait_for_start(&philo->mtdata->start_mutex, &philo->mtdata->start);

	pthread_mutex_lock(&philo->time_mutex);
	philo->last_meal_time = ft_get_time_ms();
	pthread_mutex_unlock(&philo->time_mutex);

	while (1)
	{
		pthread_mutex_lock(&philo->mtdata->death_mutex);
		dead_flag = philo->mtdata->stop;
		pthread_mutex_unlock(&philo->mtdata->death_mutex);

		if (dead_flag == true)
			break ;
		ft_print_state(philo, THINK);

		ft_eat(philo);
		if (philo->meals_eaten == philo->rdonly->num_meals)
			break ;
		ft_sleep(philo);
	}
	mtx_increment_int(&philo->mtdata->end_mutex, &philo->mtdata->end_philos);
	return (NULL);
}

bool	ft_pick_up_forks(t_philo *philo)
{
	bool	dead_flag;

	pthread_mutex_lock(&philo->mtdata->death_mutex);
	dead_flag = philo->mtdata->stop;
	pthread_mutex_unlock(&philo->mtdata->death_mutex);

	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_state(philo, LEFT);
		if (dead_flag == true)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (false);
		}
		pthread_mutex_lock(philo->right_fork);
		ft_print_state(philo, RIGHT);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_state(philo, RIGHT);
		if (dead_flag == true)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (false);
		}
		pthread_mutex_lock(philo->left_fork);
		ft_print_state(philo, LEFT);
	}
	return (true);
}

void	ft_eat(t_philo *philo)
{
	t_mtx	*meal_mtx;
	t_mtx	*init_mtx;

	ft_pick_up_forks(philo);
	meal_mtx = &philo->mtdata->meal_mutex;
	init_mtx = &philo->mtdata->init_mutex;
	philo->meals_eaten++;
	ft_precise_usleep(philo->rdonly->time_to_eat * 1000);

	pthread_mutex_lock(&philo->time_mutex);
	philo->last_meal_time = ft_get_time_ms();
	pthread_mutex_unlock(&philo->time_mutex);

	if (philo->meals_eaten == philo->rdonly->num_meals)
		mtx_increment_int(meal_mtx, &philo->mtdata->philos_full);
	ft_print_state(philo, EAT);
	ft_release_forks(philo);
}

void	ft_release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	ft_sleep(t_philo *philo)
{
	ft_print_state(philo, SLEEP);
	ft_precise_usleep(philo->rdonly->time_to_sleep * 1000);
}
