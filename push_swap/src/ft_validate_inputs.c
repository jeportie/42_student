/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_inputs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:16:37 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 18:17:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_validate_inputs(int argc, char **argv)
{
	int		i;
	int		j;
	long	value_i;
	long	value_j;

	i = 1;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i]))
			return (false);
		value_i = ft_atol(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			value_j = ft_atol(argv[j]);
			if (value_i == value_j)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
