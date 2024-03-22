/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noprint_a_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:01:16 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 21:02:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	noprint_sa(t_dclst *stack_a)
{
	t_dcnode	*first_node;
	t_dcnode	*second_node;

	if (!stack_a || !stack_a->begin || !stack_a->begin->next)
		return ; 
	first_node = stack_a->begin;
	second_node = stack_a->begin->next;
	stack_a->begin = second_node;
	first_node->next = second_node->next;
	second_node->next = first_node;
	if (first_node->next)
		first_node->next->back = first_node;
	first_node->back = second_node;
	second_node->back = NULL;
}

void	noprint_ra(t_dclst *stack_a)
{
	t_dcnode	*first_node;
	t_dcnode	*last_node;
	
	if (!stack_a || !stack_a->begin || !stack_a->begin->next)
		return ;
	first_node = stack_a->begin;
	last_node = stack_a->end;
	stack_a->begin = first_node->next;
	stack_a->begin->back = NULL;
	last_node->next = first_node;
	first_node->back = last_node;
	first_node->next = NULL;
	stack_a->end = first_node;
}

void	noprint_rra(t_dclst *stack_a)
{
	t_dcnode	*first_node;
	t_dcnode	*last_node;
	
	if (!stack_a || !stack_a->begin || !stack_a->begin->next)
		return ;
	last_node = stack_a->end;
	first_node = stack_a->begin;
	stack_a->end = last_node->back;
	stack_a->end->next = NULL;
	last_node->next = first_node;
	last_node->back = NULL;
	first_node->back = last_node;
	stack_a->begin = last_node;
}
