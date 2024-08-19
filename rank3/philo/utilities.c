/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:28:50 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/19 09:34:04 by jeportie         ###   ########.fr       */
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
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}
