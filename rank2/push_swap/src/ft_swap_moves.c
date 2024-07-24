/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:05:44 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 12:05:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap_elements(t_stack **top)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*top || !(*top)->next)
		return ;
	else if (!(*top)->next->next)
	{
		tmp = *top;
		tmp2 = (*top)->next;
		tmp->next = NULL;
		tmp2->next = tmp;
		*top = tmp2;
	}
	else
	{
		tmp = *top;
		tmp2 = (*top)->next;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
		*top = tmp2;
	}
}

void	sa(t_stack **a)
{
	ft_swap_elements(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	ft_swap_elements(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap_elements(a);
	ft_swap_elements(b);
	ft_printf("ss\n");
}
