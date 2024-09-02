/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:28:50 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/02 12:54:53 by jeportie         ###   ########.fr       */
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

void	ft_precise_usleep(long long usec, t_simu *simu)
{
	t_timeval	start;
	t_timeval	current;
	long long	elapsed;
	long long	rem;

	gettimeofday(&start, NULL);
	elapsed = 0;
	while (elapsed < usec)
	{
		if (mtx_get_bool(simu->mtdata.death_mutex, simu->mtdata.stop) == true)
			break ;
		if (mtx_get_bool(simu->mtdata.end_mutex, simu->mtdata.stop) == true)
			break ;
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
	if (simu->monitor.thread)
		pthread_join(simu->monitor.thread, NULL);
}

void	ft_free_philos(t_simu *simu)
{
	int	i;

	if (simu->forks)
	{
		i = 0;
		while (i < simu->rdonly.num_philo)
		{
			pthread_mutex_destroy(&simu->forks[i]);
			i++;
		}
		free(simu->forks);
		simu->forks = NULL;
	}
	if (simu->philos)
	{
		free(simu->philos);
		simu->philos = NULL;
	}
	pthread_mutex_destroy(&simu->mtdata.print_mutex);
	pthread_mutex_destroy(&simu->mtdata.death_mutex);
	pthread_mutex_destroy(&simu->mtdata.meal_mutex);
	pthread_mutex_destroy(&simu->mtdata.init_mutex);
	pthread_mutex_destroy(&simu->mtdata.end_mutex);
	pthread_mutex_destroy(&simu->mtdata.start_mutex);
}
