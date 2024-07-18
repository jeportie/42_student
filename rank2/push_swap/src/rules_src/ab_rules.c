/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:45:51 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/16 16:26:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	ss(t_dclst *stack_a, t_dclst *stack_b)
{
	if (!stack_a || !stack_a->begin || !stack_a->begin->next
		|| !stack_b || !stack_b->begin || !stack_b->begin->next)
		return ;
	sa(stack_a, false);
	sb(stack_b, false);
	ft_printf("ss\n");
}

void	rr(t_dclst *stack_a, t_dclst *stack_b)
{
	if (!stack_a || !stack_a->begin || !stack_a->begin->next
		|| !stack_b || !stack_b->begin || !stack_b->begin->next)
		return ;
	ra(stack_a, false);
	rb(stack_b, false);
	ft_printf("rr\n");
}

void	rrr(t_dclst *stack_a, t_dclst *stack_b)
{
	if (!stack_a || !stack_a->begin || !stack_a->begin->next
		|| !stack_b || !stack_b->begin || !stack_b->begin->next)
		return ;
	rra(stack_a, false);
	rrb(stack_b, false);
	ft_printf("rrr\n");
}
