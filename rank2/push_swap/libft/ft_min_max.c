/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:36:36 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/25 09:37:33 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_min(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_b);
	return (cost_a);
}

int	ft_max(int cost_a, int cost_b)
{
	if (cost_a < cost_b)
		return (cost_b);
	return (cost_a);
}
