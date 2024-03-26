/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/26 19:54:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	turkish_sort(t_dclst *stack_a, t_dclst *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->length == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	ft_push_initial_numbers(stack_a, stack_b);
	while (stack_a->length > 3)
	{
		ft_define_target(stack_a, stack_b);
		ft_isabove_median(stack_a, stack_b);
		ft_calculate_push_cost(stack_a, stack_b);
		ft_define_cheapest_node(stack_a);
		ft_push_to_target(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	ft_back_to_stack_a(stack_a, stack_b);
	ft_fine_tune(stack_a);
}

void	ft_topless(t_dclst *stack_a, long top, long middle, long bottom)
{
	if (middle < bottom)
		return;
	if (top < bottom)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else
		ra(stack_a);
}

void	ft_topgreater(t_dclst *stack_a, long top, long middle, long bottom)
{
	if (top < bottom)
		sa(stack_a);
	else if (middle < bottom)
		rra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	ft_sort_three(t_dclst *stack_a)
{
	long	top;
	long	middle;
	long	bottom;

	if (stack_a->length < 3)
		return ;
	top = stack_a->begin->value;
	middle = stack_a->begin->next->value;
	bottom = stack_a->end->value;
	if (top < middle)
		ft_topless(stack_a, top, middle, bottom);
	else
		ft_topgreater(stack_a, top, middle, bottom);
}

void	ft_push_initial_numbers(t_dclst *stack_a, t_dclst *stack_b)
{
	if (stack_a->length == 4)
		pb(stack_a, stack_b);
	else if (stack_a->length > 4)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
}
