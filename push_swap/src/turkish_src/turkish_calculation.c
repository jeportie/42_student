/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:44:36 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/02 20:07:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

t_dcnode*	ft_closest_smaller_number(t_dcnode *node_a, t_dclst *stack_b)
{
	t_dcnode	*current_b;
	t_dcnode	*target_b;
	long		max_value;

	current_b = stack_b->begin;
	target_b = NULL;
	max_value = LONG_MIN;
	while (current_b)
	{
		if (current_b->value < node_a->value && current_b->value > max_value)
		{
			target_b = current_b;
			max_value = current_b->value;
		}
		current_b = current_b->next;
	}
	if (!target_b)
	{
		current_b = stack_b->begin;
		while (current_b)
		{
			if (current_b->value > max_value)
			{
				target_b = current_b;
				max_value = current_b->value;
			}
			current_b = current_b->next;
		}
	}
	return (target_b);
}

t_dcnode*	ft_closest_greater_number(t_dcnode *node_b, t_dclst *stack_a)
{
	t_dcnode	*current_a;
	t_dcnode	*target_a;
	long		min_value;

	current_a = stack_a->begin;
	target_a = NULL;
	min_value = LONG_MAX;
	while (current_a)
	{
		if (current_a->value > node_b->value && current_a->value < min_value)
		{
			target_a = current_a;
			min_value = current_a->value;
		}
		current_a = current_a->next;
	}
	if (!target_a)
	{
		current_a = stack_a->begin;
		while (current_a)
		{
			if (current_a->value < min_value)
			{
				target_a = current_a;
				min_value = current_a->value;
			}
			current_a = current_a->next;
		}
	}
	return (target_a);
}

int	ft_moves_to_top(t_dclst *stack, t_dcnode *node)
{
	int	moves;

	if (node->above_median)
		moves = node->index - 1;
	else
		moves = stack->length - node->index + 1;
	return (moves);
}

void	ft_calculate_push_cost(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_a;

	current_a = stack_a->begin;
	while (current_a)
	{
		current_a->moves_a = ft_moves_to_top(stack_a, current_a);
		current_a->moves_b = ft_moves_to_top(stack_b, current_a->target);
		if (current_a->above_median == current_a->target->above_median)
		{
			if (current_a->moves_a < current_a->moves_b)
				current_a->combined_moves = current_a->moves_a;
			else
				current_a->combined_moves = current_a->moves_b;
			current_a->remaining_moves = current_a->moves_a - current_a->moves_b;
			current_a->push_cost = current_a->combined_moves 
				+ (int)ft_labs((long)current_a->remaining_moves);
		}
		else
			current_a->push_cost = current_a->moves_a + current_a->moves_b;
		current_a = current_a->next;
	}
}
