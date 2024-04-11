/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:31:05 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/09 20:07:05 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	sb(t_dclst *stack_b)
{
	t_dcnode	*first_node;
	t_dcnode	*second_node;

	if (!stack_b || !stack_b->begin || !stack_b->begin->next)
		return ; 
	first_node = stack_b->begin;
	second_node = stack_b->begin->next;
	stack_b->begin = second_node;
	first_node->next = second_node->next;
	second_node->next = first_node;
	if (first_node->next)
		first_node->next->back = first_node;
	first_node->back = second_node;
	second_node->back = NULL;
	ft_printf("sb\n");
	stack_b->moves++;
}

void	pa(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*top_b;

	if (!stack_b || !stack_b->begin)
		return ;
	top_b = stack_b->begin;
	stack_b->begin = top_b->next;
	if (stack_b->begin)
		stack_b->begin->back = NULL;
	if (!stack_a->begin)
	{
		stack_a->begin = top_b;
		stack_a->end = top_b;
		top_b->next = NULL;
	}
	else
	{
		top_b->next = stack_a->begin;
		stack_a->begin->back = top_b;
		stack_a->begin = top_b;
	}
	top_b->back = NULL;
	stack_b->length--;
	stack_a->length++;
	ft_printf("pa\n");
	stack_b->moves++;
}

void	rb(t_dclst *stack_b)
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
	ft_printf("rb\n");
	stack_b->moves++;
}

void	rrb(t_dclst *stack_b)
{
	t_dcnode	*first_node;
	t_dcnode	*last_node;
	
	if (!stack_b || !stack_b->begin || !stack_b->begin->next)
		return ;
	last_node = stack_b->end;
	first_node = stack_b->begin;
	stack_b->end = last_node->back;
	stack_b->end->next = NULL;
	last_node->next = first_node;
	last_node->back = NULL;
	first_node->back = last_node;
	stack_b->begin = last_node;
	ft_printf("rrb\n");
	stack_b->moves++;
}
