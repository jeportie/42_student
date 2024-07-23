/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:11:36 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/19 08:34:15 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_topless(t_dclst *stack_a, long top, long middle, long bottom)
{
	if (middle < bottom)
		return ;
	if (top < bottom)
	{
		rra(stack_a, true);
		sa(stack_a, true);
	}
	else
		rra(stack_a, true);
}

void	ft_topgreater(t_dclst *stack_a, long top, long middle, long bottom)
{
	if (top < bottom)
		sa(stack_a, true);
	else if (middle < bottom)
		ra(stack_a, true);
	else
	{
		sa(stack_a, true);
		rra(stack_a, true);
	}
}

void	ft_sort_three(t_dclst *stack_a)
{
	long	top;
	long	middle;
	long	bottom;

	if (stack_a->length != 3)
		return ;
	top = stack_a->begin->value;
	middle = stack_a->begin->next->value;
	bottom = stack_a->end->value;
	if (top < middle)
		ft_topless(stack_a, top, middle, bottom);
	else
		ft_topgreater(stack_a, top, middle, bottom);
}
