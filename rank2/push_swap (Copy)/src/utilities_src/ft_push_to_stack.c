/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:15:58 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/18 09:47:45 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void initialize_node(t_dcnode *node) {
    if (node) {
        node->value = 0;
        node->index = 0;
        node->push_cost = 0;
        node->above_median = false;
        node->cheapest = false;
        node->moves_to_top = 0;
        node->combined_moves = 0;
        node->segment = 0;
        node->target = NULL;
        node->back = NULL;
        node->next = NULL;
    }
}

void	ft_push_to_stack(t_dclst *stack, long value)
{
	t_dcnode	*new_node;

	new_node = (t_dcnode *)malloc(sizeof(t_dcnode));
	if (!new_node)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	initialize_node(new_node);
	new_node->value = value;
	if (!stack->begin)
	{
		stack->begin = new_node;
		stack->end = new_node;
		new_node->next = NULL;
		new_node->back = NULL;
	}
	else
	{
		new_node->next = stack->begin;
		stack->begin->back = new_node;
		new_node->back = NULL;
		stack->begin = new_node;
	}
	stack->length += 1;
}
