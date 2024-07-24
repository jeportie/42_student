/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:05:16 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 12:05:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_top_to_stack(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src || !dst)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (!dst)
	{
		*dst = tmp;
		(*dst)->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		*dst = tmp;
	}
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push_top_to_stack(a, b);
	ft_printf("pb\n");
}

void	pa(t_stack **b, t_stack **a)
{
	ft_push_top_to_stack(b, a);
	ft_printf("pa\n");
}
