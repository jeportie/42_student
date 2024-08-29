/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:36:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/29 15:18:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static void ft_print_format(t_philo *philo, long long time, const char *format)
{
	pthread_mutex_lock(&philo->mtdata->print_mutex);
	if (mtx_get_bool(philo->mtdata->death_mutex, philo->mtdata->someone_died) == false)
		printf("[%lldms] %d %s\n", time, philo->id, format);
	pthread_mutex_unlock(&philo->mtdata->print_mutex);
}

void	ft_print_state(t_philo *philo, int state)
{
	long long time;

	time = ft_get_time_ms() - philo->rdonly->start_time;
	if (state == DEAD)
	{
		pthread_mutex_lock(&philo->mtdata->print_mutex);
		printf(RED "[%lldms] %d died\n" RESET, time, philo->id);
		pthread_mutex_unlock(&philo->mtdata->print_mutex);
		return;
	}
	if (state == THINK)
		ft_print_format(philo, time, "is thinking");
	if (state == LEFT || state == RIGHT)
		ft_print_format(philo, time, "has taken a fork");
	if (state == EAT)
		ft_print_format(philo, time, "is eating");
	if (state == SLEEP)
		ft_print_format(philo, time, "is sleeping");
}

void	ft_print_params(t_rdonly params)
{
	printf("Printing Params...\n\n");
	printf("num_philo : %d\n", params.num_philo);
	printf("time_to_die : %d\n", params.time_to_die);
	printf("time_to_eat : %d\n", params.time_to_eat);
	printf("time_to_sleep : %d\n", params.time_to_sleep);
	printf("(optional)num_meals : %d\n", params.num_meals);
}

void	ft_print_philos(t_simu simu)
{
	int	i;

	i = 0;
	while (i < simu.rdonly.num_philo)
	{
		printf("\nPhilo %d:\n\n", i);
		printf("id : %d\n", i + 1);
		printf("thread id: %lu\n", (unsigned long)simu.philos[i].thread);
		printf("r fork : %p, l fork : %p)\n",
				simu.philos[i].right_fork, simu.philos[i].left_fork);
		i++;
	}
}

void	ft_print_start_stop(t_simu *simu, bool choice)
{
	if (choice == true)
		printf(GREEN "[0ms] Simulation Starts.\n" RESET);
	else
	{
		printf(GREEN "[%lldms] Simulation Ended.\n\n" RESET,
		ft_get_time_ms() - simu->rdonly.start_time);
	}
}

void	ft_print_parsing(t_simu simu)
{
	ft_print_params(simu.rdonly);
	ft_print_philos(simu);
	printf("\n");
}
