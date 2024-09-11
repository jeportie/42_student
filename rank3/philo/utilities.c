/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:28:50 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/11 11:13:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_perror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

long long	ft_get_time_ms(void)
{
	t_timeval	tv;
	long long	time;
	int			succes;

	succes = gettimeofday(&tv, NULL);
	if (succes == -1)
	{
		ft_perror("Error, time not found.\n");
		return (-1);
	}
	time = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
	return (time);
}

static long long	ft_get_elapsed_time_us(t_timeval start, t_timeval end)
{
	long long	sec;
	long long	usec;

	sec = end.tv_sec - start.tv_sec;
	usec = end.tv_usec - start.tv_usec;
	return (sec * 1000000L + usec);
}

void	ft_precise_usleep(long long usec)
{
	t_timeval	start;
	t_timeval	current;
	long long	elapsed;
	long long	rem;

	gettimeofday(&start, NULL);
	elapsed = 0;
	while (elapsed < usec)
	{
		gettimeofday(&current, NULL);
		elapsed = ft_get_elapsed_time_us(start, current);
		rem = usec - elapsed;
		if (rem > 1000)
			usleep(rem / 2);
		else if (rem > 0)
			usleep(rem);
	}
}

void	ft_stop_threads(t_simu *simu)
{
	int	i;

	if (simu->philos)
	{
		i = 0;
		while (i < simu->rdonly.num_philo)
		{
			if (simu->philos[i].thread)
				pthread_join(simu->philos[i].thread, NULL);
			i++;
		}
	}
}

void	ft_destroy_mutex(t_simu *simu)
{
	pthread_mutex_destroy(&simu->mtdata.print_mutex.pmutex);
	pthread_mutex_destroy(&simu->mtdata.stop_mutex);
	pthread_mutex_destroy(&simu->mtdata.meal_mutex);
	pthread_mutex_destroy(&simu->mtdata.go_mutex);
	pthread_mutex_destroy(&simu->mtdata.end_mutex);
	pthread_mutex_destroy(&simu->mtdata.start_mutex);
}

void	ft_free_forks(t_simu *simu)
{
	int	i;

	if (simu->forks)
	{
		i = 0;
		while (i < simu->rdonly.num_philo)
		{
			pthread_mutex_destroy(&simu->forks[i].fork_mutex);
			pthread_mutex_destroy(&simu->forks[i].lock_mutex);
			i++;
		}
		free(simu->forks);
		simu->forks = NULL;
	}
}

void	ft_free_philos(t_simu *simu)
{
	int	i;

	ft_free_forks(simu);
	if (simu->philos)
	{
		i = 0;
		while (i < simu->rdonly.num_philo)
		{
			pthread_mutex_destroy(&simu->philos[i].time_mutex);
			pthread_mutex_destroy(&simu->philos[i].finish_mutex);
			i++;
		}
		free(simu->philos);
		simu->philos = NULL;
	}
	ft_destroy_mutex(simu);
}

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

void	ft_update_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->time_mutex);
	if (philo->rdonly->num_philo % 2 == 0)
		philo->last_meal_time = ft_get_time_ms();
	else if (philo->rdonly->num_philo % 2 == 1)
		philo->last_meal_time = ft_get_time_ms() + (philo->rdonly->time_to_eat / 4);
	pthread_mutex_unlock(&philo->time_mutex);
}
