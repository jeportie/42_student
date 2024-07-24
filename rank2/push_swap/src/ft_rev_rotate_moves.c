/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:05:30 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 12:05:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rev_rotate(t_stack **top)
{
	t_stack	*last;
	t_stack	*last2;

	if (!(*top) || !(*top)->next)
		return ;
	last = ft_stacklast(*top);
	last2 = ft_before_last(*top);
	last2->next = NULL;
	last->next = *top;
	*top = last;
}

void	rra(t_stack **a)
{
	ft_rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	ft_rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}
