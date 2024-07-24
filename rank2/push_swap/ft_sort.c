/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:05:58 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 13:21:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_index_in_stack(t_stack **lst)
{
	int		i;
	int		mid;
	t_stack	*stack;

	i = 0;
	stack = *lst;
	mid = ft_mid_stack(stack);
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->is_in_top = 1;
		else
			stack->is_in_top = 0;
		stack = stack->next;
		i++;
	}
}

void	ft_last_sort(t_stack **a)
{
	while ((*a)->nb != ft_find_min(*a)->nb)
	{
		ft_index_in_stack(a);
		if (ft_find_min(*a)->is_in_top)
			ra(a);
		else
			rra(a);
	}
}

void	ft_sort_stack(t_stack **a, t_stack **b)
{
	if (!ft_is_sorted(*a))
	{
		ft_sort_b(a, b);
		ft_sort_three_a(a);
//		ft_print_stack(*a);
//		ft_print_stack(*b);
		ft_sort_a(a, b);
		ft_last_sort(a);
		ft_print_stack(*a);
		ft_print_stack(*b);
	}
}
