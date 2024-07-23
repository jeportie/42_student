/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:08:59 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/23 10:47:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	ft_calculate_cost(t_dclst *stack_a)
{
	t_dcnode	*current;
	int			moves_to_top;

	current = stack_a->begin;
	while (current)
	{

		moves_to_top = ft_moves_to_top(stack_a, current);
		if (current->above_median)
			current->push_cost = moves_to_top;
		else
			current->push_cost = stack_a->length - moves_to_top;

		current = current->next;
	}

}

bool	ft_is_seg(t_dclst *stack_a, int *seg)
{
	t_dcnode	*current;
	
	current = stack_a->begin;
	while (current)
	{
		if (current->segment == *seg)
			return (true);
		current = current->next;
	}
	return (false);
}

void	ft_push_to_b(t_dclst *stack_a, t_dclst *stack_b, int *seg)
{
	t_dcnode	*current;

	current = stack_a->begin;
	while (current)
	{
		if (current->segment == *seg && current->cheapest)
		{
			while (stack_a->begin != current)
			{
				if (current->above_median)
					ra(stack_a, true);
				else
					rra(stack_a, true);
			}
			pb(stack_a, stack_b);
			if (!ft_is_seg(stack_a, seg))
				*seg = *seg + 1;
			current = stack_a->begin;
			break;
		}
		else
			current = current->next;
	}
}

void	ft_get_segment_cheapest(t_dclst *stack, int seg)
{
	t_dcnode	*current;
	t_dcnode	*cheapest;
	int			cheapest_cost;

	current = stack->begin;
	cheapest = NULL;
	cheapest_cost = INT_MAX;
	while (current)
	{
		if (current->segment == seg && current->push_cost < cheapest_cost)
		{
			cheapest_cost = current->push_cost;
			cheapest = current;
			break ;
		}
		current = current->next;
	}
	if (cheapest)
		cheapest->cheapest = true;
}

void	ft_sort_b(t_dclst *stack_a, t_dclst *stack_b)
{
	int		seg;

	seg = 1;
	while (stack_a->length > 3)
	{
		ft_isabove_median(stack_a, stack_b);
		ft_actualise_indexes(stack_a, stack_b);
		ft_calculate_cost(stack_a);
		ft_get_segment_cheapest(stack_a, seg);
		ft_push_to_b(stack_a, stack_b, &seg);
	}
}
