/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:56:06 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 14:32:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_find_cheapest(t_stack *a)
{
	t_stack	*stack_a;

	stack_a = a;
	if (!stack_a)
		return (NULL);
	while (stack_a)
	{
		if (stack_a->is_cheapest)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}

void	ft_get_cheapest(t_stack **a)
{
	t_stack	*stack_a;
	t_stack	*cheapest;
	int		cheapest_cost;

	cheapest = NULL;
	cheapest_cost = INT_MAX;
	stack_a = *a;
	while (stack_a)
	{
		if (stack_a->total_cost < cheapest_cost)
		{
			cheapest_cost = stack_a->total_cost;
			cheapest = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (cheapest)
		cheapest->is_cheapest = 1;
}

void	ft_target_cost(t_stack **a, t_stack **b)
{
	t_stack	*stack_a;
	int		stack_len;

	stack_a = *a;
	stack_len = ft_stack_size(*b);
	while (stack_a)
	{
		if (stack_a->target_node->is_in_top)
			stack_a->target_cost = stack_a->target_node->index;
		else
			stack_a->target_cost = stack_len - stack_a->target_node->index;
		stack_a = stack_a->next;
	}
}

int	ft_calculate_node_cost(t_stack *node, int stack_length)
{
	if (node->is_in_top)
		return (node->index);
	else
		return (stack_length - node->index);
}

void	ft_total_cost(t_stack *a, t_stack *b)
{
	int		stack_len_a;
	int		stack_len_b;
	t_stack	*stack_a;
	int		cost_a;
	int		cost_b;

	stack_len_a = ft_stack_size(a);
	stack_len_b = ft_stack_size(b);
	stack_a = a;
	while (stack_a)
	{
		cost_a = ft_calculate_node_cost(stack_a, stack_len_a);
		cost_b = ft_calculate_node_cost(stack_a->target_node, stack_len_b);
		if (stack_a->is_in_top == stack_a->target_node->is_in_top)
			stack_a->total_cost = cost_a + cost_b - ft_min(cost_a, cost_b);
		else
			stack_a->total_cost = cost_a + cost_b;
		stack_a = stack_a->next;
	}
}
