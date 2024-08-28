/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:36:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/27 19:01:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static void ft_print_format(t_philo *philo, long long time, const char *format)
{
	printf("[%lldms]\t %d %s\n", time, philo->id, format);
}

void	ft_print_state(t_philo *philo, int state)
{
	long long time;

	time = ft_get_time_ms() - START_TIME;
	if (state == DEAD)
		printf(RED "[%lldms]\t %d died.\n" RESET, time, philo->id);
	if (state == THINK)
		ft_print_format(philo, time, "is thinking.");
	if (state == LEFT)
		ft_print_format(philo, time, "has taken the left fork.");
	if (state == RIGHT)
		ft_print_format(philo, time, "has taken the right fork.");
	if (state == EAT)
		ft_print_format(philo, time, "is eating.");
	if (state == ULEFT)
		ft_print_format(philo, time, "has released the left fork.");
	if (state == URIGHT)
		ft_print_format(philo, time, "has released the right fork.");
	if (state == SLEEP)
		ft_print_format(philo, time, "is sleeping.");

}

void	ft_print_params(t_params params)
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
	while (i < simu.params.num_philo)
	{
		printf("\nPhilo %d:\n\n", i);
		printf("id : %d\n", i + 1);
		printf("thread id: %lu\n", (unsigned long)simu.philos[i].thread);
		printf("r fork : %p, l fork : %p)\n",
				simu.philos[i].right_fork, simu.philos[i].left_fork);
		i++;
	}
}

void	ft_print_parsing(t_simu simu)
{
	ft_print_params(simu.params);
	ft_print_philos(simu);
	printf("\n");
}
