/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:04:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 11:15:41 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_prep_stack_a(t_stack **a)
{
	int	*pivots;
	int	size;

	size = ft_stack_size(*a);
	pivots = malloc(4 * sizeof(int));
	if (!pivots)
		return ;
	pivots = ft_find_pivots(*a, size, pivots);
	ft_set_cheapest_to_null(a);
	ft_assign_segment(a, pivots);
	free(pivots);
}

void	ft_assign_cost_in_a(t_stack **a)
{
	t_stack	*stack_a;
	int		stack_len;

	stack_a = *a;
	stack_len = ft_stack_size(stack_a);
	ft_index_in_stack(a);
	while (stack_a)
	{
		stack_a->total_cost = ft_calculate_node_cost(stack_a, stack_len);
		stack_a = stack_a->next;
	}
}

void	ft_get_cheapest_by_segment(t_stack **a, int seg)
{
	t_stack	*stack_a;
	t_stack	*cheapest;
	int		cheapest_cost;

	cheapest = NULL;
	cheapest_cost = INT_MAX;
	stack_a = *a;
	while (stack_a)
	{
		if (stack_a->total_cost < cheapest_cost && stack_a->segment == seg)
		{
			cheapest_cost = stack_a->total_cost;
			cheapest = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (cheapest)
		cheapest->is_cheapest = 1;
}

void	ft_node_to_top(t_stack **a, t_stack *node)
{
	int	cost_a;
	int	stack_len;

	stack_len = ft_stack_size(*a);
	cost_a = ft_calculate_node_cost(node, stack_len);
	if (node->is_in_top)
		ft_single_rotate(a, cost_a, ra);
	else
		ft_single_rotate(a, cost_a, rra);
}

void	ft_sort_b(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		size;
	int		seg;

	seg = -1;
	size = ft_stack_size(*a);
	ft_prep_stack_a(a);
	while (++seg <= 5)
	{
		current = *a;
		while (current && size > 3)
		{
			ft_assign_cost_in_a(a);
			ft_get_cheapest_by_segment(a, seg);
			if (current->segment == seg && current->is_cheapest)
			{
				ft_node_to_top(a, current);
				pb(a, b);
				current = *a;
				size--;
			}
			else
				current = current->next;
		}
	}
}
