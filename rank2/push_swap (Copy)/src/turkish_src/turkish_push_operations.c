/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_push_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:53:52 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/23 20:57:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	ft_define_target(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_b;

	if (!stack_a || !stack_b)
		return ;
	current_b = stack_b->begin;
	while (current_b)
	{
		current_b->target = ft_closest_greater_number(current_b, stack_a);
		current_b = current_b->next;
	}
}

void ft_back_to_stack_a(t_dclst *stack_a, t_dclst *stack_b)
{
    while (stack_b->length)
	{
        ft_actualise_indexes(stack_a, stack_b);
        ft_isabove_median(stack_a, stack_b);
        ft_define_target(stack_b, stack_a);
        ft_calculate_push_cost(stack_a, stack_b);
        ft_push_to_target(stack_a, stack_b);
    }

}

static void	ft_helper(t_dclst *stack_a, t_dcnode *min_node)
{
	int	moves;

	moves = ft_moves_to_top(stack_a, min_node);
	while (moves--)
	{
		if (min_node->above_median)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
}

void	ft_fine_tune(t_dclst *stack_a)
{
	t_dcnode	*current;
	t_dcnode	*min_node;
	long		min_value;

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
	ft_helper(stack_a, min_node);
}
