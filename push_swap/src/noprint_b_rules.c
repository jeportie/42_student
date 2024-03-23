/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noprint_b_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:04:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/23 21:07:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	noprint_sb(t_dclst *stack_b)
{
	t_dcnode	*first_node;
	t_dcnode	*second_node;

	if (!stack_b || !stack_b->begin || !stack_b->begin->next)
		return ; 
	if (stack_b->length == 2)
	{
		noprint_sa(stack_b);
		return ;
	}
	first_node = stack_b->begin;
	second_node = stack_b->begin->next;
	stack_b->begin = second_node;
	first_node->next = second_node->next;
	second_node->next = first_node;
	if (first_node->next)
		first_node->next->back = first_node;
	first_node->back = second_node;
	second_node->back = NULL;
}

void	noprint_rb(t_dclst *stack_b)
{
	t_dcnode	*first_node;
	t_dcnode	*last_node;
	
	if (!stack_b || !stack_b->begin || !stack_b->begin->next)
		return ;
	first_node = stack_b->begin;
	last_node = stack_b->end;
	stack_b->begin = first_node->next;
	stack_b->begin->back = NULL;
	last_node->next = first_node;
	first_node->back = last_node;
	first_node->next = NULL;
	stack_b->end = first_node;
}

void	noprint_rrb(t_dclst *stack_b)
{
	t_dcnode	*first_node;
	t_dcnode	*last_node;
	
	if (!stack_b || !stack_b->begin || !stack_b->begin->next)
		return ;
	if (stack_b->length == 2)
	{
		noprint_sa(stack_b);
		return ;
	}
	last_node = stack_b->end;
	first_node = stack_b->begin;
	stack_b->end = last_node->back;
	stack_b->end->next = NULL;
	last_node->next = first_node;
	last_node->back = NULL;
	first_node->back = last_node;
	stack_b->begin = last_node;
}
