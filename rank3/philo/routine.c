/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:06:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/11 13:52:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * TODO:
 * Faire des notes dans chaque fichier pour expliquer
 * Faire un UML sur draw.io et mettre toute l'architecture sur papier pour 
 * s'entrainer
 * Bug de parsing quand mauvais format -> segault et free en trop
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

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	mtx_increment_int(&philo->mtdata->go_mutex, &philo->mtdata->go_count);
	ft_wait_for_start(&philo->mtdata->start_mutex, &philo->mtdata->start_flag);
	mtx_set_llong(&philo->time_mutex, &philo->last_meal_time, ft_get_time_ms());
	if (philo->rdonly->num_philo == 1)
	{
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		ft_print_state(philo, LEFT);
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		ft_precise_usleep(1000 * philo->rdonly->time_to_die);
		return (NULL);
	}
	ft_simulation_loop(philo);
	ft_check_remaining_locks(philo);
	mtx_increment_int(&philo->mtdata->end_mutex, &philo->mtdata->end_count);
	if (DEBBUG == true)
		ft_print_state(philo, STOP);
	return (NULL);
}
