/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:36:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/19 13:13:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_print_intro(void)
{
	printf("Let's start the simluation...\n3...\n");
	sleep(1);
	printf("2...\n");
	sleep(1);
	printf("1...\n");
	sleep(1);
	printf("GO!\n");
}

void	ft_print_params(t_params params)
{
	printf("Printing Params...\n\n");
	printf("num_philo : %d\n", params.num_philo);
	printf("time_to_die : %d\n", params.time_to_die);
	printf("time_to_eat : %d\n", params.time_to_eat);
	printf("time_to_sleep : %d\n", params.time_to_sleep);
	printf("(optional)num_meals : %d\n", params.num_meals);
	printf("someone_died : %d\n", params.someone_died);
}

void	ft_print_parsing(t_simu simu)
{
	ft_print_params(simu.params);
}
