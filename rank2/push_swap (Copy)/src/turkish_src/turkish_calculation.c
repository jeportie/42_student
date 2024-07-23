/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:44:36 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/18 10:30:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

static void	ft_helperb(t_dcnode *current_b, t_dcnode *target_b, long max_value,
		t_dclst *stack_b)
{
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
}

t_dcnode	*ft_closest_smaller_number(t_dcnode *node_a, t_dclst *stack_b)
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
	ft_helperb(current_b, target_b, max_value, stack_b);
	return (target_b);
}

static void	ft_helpera(t_dcnode *current_a, t_dcnode *target_a, long min_value,
		t_dclst *stack_a)
{
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
}

t_dcnode	*ft_closest_greater_number(t_dcnode *node_b, t_dclst *stack_a)
{
	t_dcnode	*current_a;
	t_dcnode	*target_a;
	long		min_value;

	current_a = stack_a->begin;
	target_a = NULL;
	min_value = LONG_MAX;
	if (!current_a)
		return (NULL);
	while (current_a)
	{
		if (current_a->value > node_b->value && current_a->value < min_value)
		{
			target_a = current_a;
			min_value = current_a->value;
		}
		current_a = current_a->next;
	}
	ft_helpera(current_a, target_a, min_value, stack_a);
	return (target_a);
}

t_dcnode	*ft_ischeapest(t_dclst *stack)
{
	t_dcnode	*current;
	t_dcnode	*cheapest_node;
	int			lowest_cost;

	current = stack->begin;
	cheapest_node = NULL;
	lowest_cost = INT_MAX;
	while (current != NULL)
	{
		if (current->push_cost < lowest_cost)
		{
			lowest_cost = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}
