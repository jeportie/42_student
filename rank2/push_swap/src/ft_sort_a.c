/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:47:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/25 09:30:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_find_target_b_in_a(t_stack *b, t_stack *a)
{
	t_stack	*stack_a;
	t_stack	*target;
	int		target_nb;

	while (b)
	{
		target = NULL;
		target_nb = INT_MAX;
		stack_a = a;
		while (stack_a)
		{
			if (stack_a->nb > b->nb && stack_a->nb < target_nb)
			{
				target_nb = stack_a->nb;
				target = stack_a;
			}
			stack_a = stack_a->next;
		}
		if (target_nb == INT_MAX)
			b->target_node = ft_find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	ft_prep_stack_b(t_stack **b, t_stack **a)
{
	ft_index_in_stack(a);
	ft_index_in_stack(b);
	ft_find_target_b_in_a(*b, *a);
	ft_target_cost(b, a);
	ft_total_cost(*b, *a);
	ft_set_cheapest_to_null(b);
	ft_get_cheapest(b);
}

void	ft_both_to_top(t_stack **b, t_stack *cheapest, t_stack **a, int cost_b)
{
	int	target_cost;

	target_cost = ft_calculate_node_cost(cheapest->target_node,
			ft_stack_size(*a));
	if (cheapest->is_in_top)
		ft_double_rotate(a, b, ft_min(cost_b, target_cost), rr);
	else
		ft_double_rotate(a, b, ft_min(cost_b, target_cost), rrr);
	if (cost_b < target_cost)
	{
		if (cheapest->is_in_top)
			ft_single_rotate(a, target_cost - cost_b, ra);
		else
			ft_single_rotate(a, target_cost - cost_b, rra);
	}
	else if (cost_b > target_cost)
	{
		if (cheapest->is_in_top)
			ft_single_rotate(b, cost_b - target_cost, rb);
		else
			ft_single_rotate(b, cost_b - target_cost, rrb);
	}
}

void	ft_b_and_target_to_top(t_stack **b, t_stack *cheapest, t_stack **a)
{
	int	cost_b;
	int	target_cost;

	target_cost = ft_calculate_node_cost(cheapest->target_node,
			ft_stack_size(*a));
	cost_b = ft_calculate_node_cost(cheapest, ft_stack_size(*b));
	if ((cheapest->is_in_top && cheapest->target_node->is_in_top)
		|| (!cheapest->is_in_top && !cheapest->target_node->is_in_top))
		ft_both_to_top(b, cheapest, a, cost_b);
	else
	{
		if (cheapest->is_in_top)
		{
			ft_single_rotate(a, target_cost, rra);
			ft_single_rotate(b, cost_b, rb);
		}
		else
		{
			ft_single_rotate(a, target_cost, ra);
			ft_single_rotate(b, cost_b, rrb);
		}
	}
}

void	ft_sort_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (*b)
	{
		ft_prep_stack_b(b, a);
		cheapest = ft_find_cheapest(*b);
		ft_b_and_target_to_top(b, cheapest, a);
		pa(b, a);
	}
}
