/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:00:46 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/25 15:52:20 by jeportie         ###   ########.fr       */
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
	int		size;
	int		i;
	long	number;

	size = stack_a->length;
	i = 0;
	while (i < size)
	{
		number = stack_a->begin->value;
		if (((number >> bit) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	while (stack_b->length > 0)
	{
		pa(stack_a, stack_b);
	}
}

void	radix_sort(t_dclst *stack_a, t_dclst *stack_b)
{
	int	bit;
	int	max_bits;

	if (!stack_a || !stack_b)
		return ;
	max_bits = ft_find_max_bits(stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		ft_apply_bitwise_sort(stack_a, stack_b,  bit);
		bit++;
	}
}
