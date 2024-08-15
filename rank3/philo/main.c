/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:35:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/15 17:53:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void ft_perror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

void ft_print_intro()
{
	printf("Let's start the simluation...\n3...\n");
	sleep(1);
	printf("2...\n");
	sleep(1);
	printf("1...\n");
	sleep(1);
	printf("GO!\n");
}

void	ft_print_params(t_params *params)
{
	printf("Printing Params...\n\n");
	printf("num_philo : %d\n", params->num_philo);
	printf("time_to_die : %d\n", params->time_to_die);
	printf("time_to_eat : %d\n", params->time_to_eat);
	printf("time_to_sleep : %d\n", params->time_to_sleep);
	printf("(optional)num_meals : %d\n", params->num_meals);
	printf("someone_died : %d\n", params->someone_died);
}

void	ft_print_parsing(t_simu simu)
{
	ft_print_params(simu.params);
}

long long ft_get_time_ms()
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
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

int	main(int ac, char **av)
{
	long long	start_time;
	long long	current_time;

	ft_print_intro();
	start_time = ft_get_time_ms();
	printf("The start time is %lld milliseconds\n", start_time - start_time);
	usleep(23 * 1000);
	current_time = ft_get_time_ms();
	printf("The elapsed time is %lld milliseconds\n", current_time - start_time);
	return (0);
}
