/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:45:51 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 21:04:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	ss(t_dclst *stack_a, t_dclst *stack_b)
{
	if (!stack_a || !stack_a->begin || !stack_a->begin->next 
			|| !stack_b || !stack_b->begin || !stack_b->begin->next)
		return ; 
	noprint_sa(stack_a); 
	noprint_sb(stack_b);
	ft_printf("ss\n");
}

void	rr(t_dclst *stack_a, t_dclst *stack_b)
{
	if (!stack_a || !stack_a->begin || !stack_a->begin->next 
			|| !stack_b || !stack_b->begin || !stack_b->begin->next)
		return ; 
	noprint_ra(stack_a); 
	noprint_rb(stack_b);
	ft_printf("rr\n");
}

void	rrr(t_dclst *stack_a, t_dclst *stack_b)
{
	if (!stack_a || !stack_a->begin || !stack_a->begin->next 
			|| !stack_b || !stack_b->begin || !stack_b->begin->next)
		return ; 
	noprint_rra(stack_a); 
	noprint_rrb(stack_b);
	ft_printf("rrr\n");
}
