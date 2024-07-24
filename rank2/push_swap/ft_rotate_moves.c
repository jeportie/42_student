/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:05:37 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 12:05:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_rotate(t_stack **top)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*top) || !(*top)->next)
		return ;
	first = *top;
	last = ft_stacklast(*top);
	*top = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
