/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_target.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:07:21 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/16 16:27:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	ft_execute_direct_moves(t_dclst *stack_a, t_dclst *stack_b, t_dcnode *cheapest_node)
{
	while (cheapest_node != stack_a->begin)
	{
		if (cheapest_node->above_median)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
	while (cheapest_node->target != stack_b->begin)
	{
		if (cheapest_node->target->above_median)
			rb(stack_b, true);
		else
			rrb(stack_b, true);
	}
}

void	ft_execute_combined_moves(t_dclst *stack_a, t_dclst *stack_b, t_dcnode *cheapest_node)
{
	while (cheapest_node != stack_a->begin && cheapest_node->target != stack_b->begin)
	{
		if (cheapest_node->above_median)
			rr(stack_a, stack_b);
		else
			rrr(stack_a, stack_b);
		
	}
}

void	ft_adjust_remaining_moves(t_dclst *stack_a, t_dclst *stack_b, t_dcnode *cheapest_node)
{
	while (cheapest_node != stack_a->begin)
	{
		if (cheapest_node->above_median)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
	while (cheapest_node->target != stack_b->begin)
	{
		if (cheapest_node->above_median)
			rb(stack_b, true);
		else
			rrb(stack_b, true);
	}
}

void	ft_push_to_target(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*cheapest_node;

	cheapest_node = ft_ischeapest(stack_a);
	if (!cheapest_node)
		return ;

	if (cheapest_node->above_median == cheapest_node->target->above_median)
	{
		ft_execute_combined_moves(stack_a, stack_b, cheapest_node);
		ft_adjust_remaining_moves(stack_a, stack_b, cheapest_node);

	}
	else
		ft_execute_direct_moves(stack_a, stack_b, cheapest_node);
	pb(stack_a, stack_b);
}
