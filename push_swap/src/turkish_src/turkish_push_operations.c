/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_push_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:53:52 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/08 16:03:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	ft_define_target(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_a;

	if (!stack_a || !stack_b || !stack_b->length)
		return ;
	current_a = stack_a->begin;
	while (current_a)
	{
		current_a->target = ft_closest_smaller_number(current_a, stack_b);
		current_a = current_a->next;
	}
}

void	ft_back_to_stack_a(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_b;	
	int			moves;
	int			i;

	moves = 0;
	while (stack_b->length)
	{
		current_b = stack_b->begin;
		ft_actualise_indexes(stack_a, stack_b);
		ft_isabove_median(stack_a, stack_b),
		current_b->target = ft_closest_greater_number(current_b, stack_a);
		moves = ft_moves_to_top(stack_a, current_b->target);
		i = 0;
		while (i < moves)
		{
			if (current_b->target->above_median)
				ra(stack_a);
			else
				rra(stack_a);
			i++;
		}
		pa(stack_a, stack_b);
	}
}

void	ft_fine_tune(t_dclst *stack_a)
{
	t_dcnode	*current;
	t_dcnode	*min_node;
	long		min_value;
	int			moves;

	ft_define_index(stack_a);
	ft_mark_above_median(stack_a);
	current = stack_a->begin;
	min_value = LONG_MAX;
	min_node = NULL;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_node = current;
		}
		current = current->next;
	}
	moves = ft_moves_to_top(stack_a, min_node);
	while (moves--)
	{
		if (min_node->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
