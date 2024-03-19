/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:43:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/19 23:35:14 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_dclst *stack_a)
{
	t_dcnode	*first_node;
	t_dcnode	*second_node;

	if (!stack_a || !stack_a->begin || !stack_a->begin->next)
		return (0);
	first = stack_a->begin;
	second = stack_a->begin->next;
	stack_a->begin = second;
	first->next = second->next;
	second->next = first;
	if (first->next)
		first->next->back = first;
	first->back = second;
	second->back = NULL;
	ft_printf("sa\n");
}

void	pa(t_dclst *stack_a, t_dclst *stack_b);

void	ra(t_dclst *stack_a);

void	rra(t_dclst *stack_a);
