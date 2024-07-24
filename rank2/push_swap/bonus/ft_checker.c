/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:55:23 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 14:25:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_checker(t_stack **a, t_stack **b, char **line)
{
	while (*line)
	{
		ft_mv_read_exe(a, b, line);
		free (*line);
		*line = NULL;
		*line = get_next_line(0);
	}
	if (!ft_is_sorted(*a))
		ft_putstr_fd("KO\n", 1);
	else if (*b)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	*line = NULL;
}
