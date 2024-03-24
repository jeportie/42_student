/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:00:46 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/24 14:13:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

long	ft_labs(long value)
{
	if (value < 0)
		return (-value);
	return value;
}

int		ft_find_max_bits(t_dclst *stack)
{
	int		max_bits;
	long	max_value;
	t_dcnode *current;

	max_bits = 0;
	max_value = 0;
	current = stack->begin;
	while (current)
	{
		if (ft_labs(current->value) > max_value)
			max_value = ft_labs(current->value);
		current = current->next;
	}
	while (max_value >> max_bits)
		max_bits++;
	return (max_bits);
}

void	ft_apply_bitwise_sort(t_dclst *stack_a, t_dclst *stack_b, int bit)
{

}

void	radix_sort(t_dclst *stack_a, t_dclst *stack_b)
{

}
