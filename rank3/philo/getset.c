/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:02:14 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/27 12:02:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

bool	mtx_get_bool(t_mtx mutex, bool value)
{
	bool	ret;
	
	pthread_mutex_lock(&mutex);
	ret = value;
	pthread_mutex_unlock(&mutex);

	return (ret);
}

void	mtx_set_bool(t_mtx mutex, bool *dest, bool value)
{
	pthread_mutex_lock(&mutex);
	*dest = value;
	pthread_mutex_unlock(&mutex);
}

int	mtx_get_int(t_mtx mutex, int value)
{
	int	ret;
	
	pthread_mutex_lock(&mutex);
	ret = value;
	pthread_mutex_unlock(&mutex);

	return (ret);
}

void	mtx_set_int(t_mtx mutex, int *dest, int value)
{
	pthread_mutex_lock(&mutex);
	*dest = value;
	pthread_mutex_unlock(&mutex);
}

int mtx_increment_int(t_mtx *mutex, int *dest)
{
    int new_value;

    pthread_mutex_lock(mutex);
    *dest += 1;
    new_value = *dest;
    pthread_mutex_unlock(mutex);
    return new_value;
}


long long	mtx_get_longlong(t_mtx mutex, long long value)
{
	long long	ret;
	
	pthread_mutex_lock(&mutex);
	ret = value;
	pthread_mutex_unlock(&mutex);

	return (ret);
}

void	mtx_set_longlong(t_mtx mutex, long long *dest, long long value)
{
	pthread_mutex_lock(&mutex);
	*dest = value;
	pthread_mutex_unlock(&mutex);
}
