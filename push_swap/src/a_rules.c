/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:43:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 17:12:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	sa(t_dclst *stack_a)
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
	ft_printf("sa\n");
}

void	pa(t_dclst *stack_a, t_dclst *stack_b);

void	ra(t_dclst *stack_a);

void	rra(t_dclst *stack_a);
