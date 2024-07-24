/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:05:02 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 12:05:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_double_rotate(t_stack **a, t_stack **b, int count,
		void (*move)(t_stack **, t_stack **))
{
	int	i;

	i = 0;
	while (i < count)
	{
		move(a, b);
		i++;
	}
}

void	ft_single_rotate(t_stack **stack, int count, void (*move)(t_stack **))
{
	int	i;

	i = 0;
	while (i < count)
	{
		move(stack);
		i++;
	}
}
