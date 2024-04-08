/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_push_cost.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:04:44 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/08 19:44:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

int	ft_moves_to_top(t_dclst *stack, t_dcnode *node)
{
	int	moves;

	ft_define_index(stack);
	ft_mark_above_median(stack);
	if (node->above_median)
		moves = node->index - 1;
	else
		moves = stack->end->index - node->index + 1;
	return (moves);
}

int ft_evaluate_combined_moves(t_dclst *stack_a, t_dclst *stack_b, t_dcnode *node)
{
    int moves_a_to_top;
    int moves_b_to_top;
    int combined_moves;

    moves_a_to_top = ft_moves_to_top(stack_a, node);
    moves_b_to_top = ft_moves_to_top(stack_b, node->target);

    if (moves_a_to_top > moves_b_to_top)
    {
        combined_moves = moves_a_to_top;
    }
    else
    {
        combined_moves = moves_b_to_top;
    }

    node->combined_moves = combined_moves;

    return combined_moves;
}

int ft_evaluate_direct_moves(t_dclst *stack_a, t_dclst *stack_b, t_dcnode *node)
{
    int moves_a_to_top;
    int moves_b_to_top;
    int direct_moves;

    moves_a_to_top = ft_moves_to_top(stack_a, node);
    moves_b_to_top = ft_moves_to_top(stack_b, node->target);

    direct_moves = moves_a_to_top + moves_b_to_top;

    node->moves_to_top = moves_a_to_top;
    node->target->moves_to_top = moves_b_to_top;

    return direct_moves;
}

void ft_select_optimal_strategy(t_dcnode *node)
{
    int combined_moves_cost;
    int direct_moves_cost;

    combined_moves_cost = node->combined_moves + (int)ft_labs(node->moves_to_top - node->target->moves_to_top);
    direct_moves_cost = node->moves_to_top + node->target->moves_to_top;

    if (combined_moves_cost < direct_moves_cost)
    {
        node->push_cost = combined_moves_cost;
        node->remaining_moves = node->moves_to_top - node->target->moves_to_top;
    }
    else
        node->push_cost = direct_moves_cost;
}

void ft_calculate_push_cost(t_dclst *stack_a, t_dclst *stack_b)
{
    t_dcnode *current_node;

    current_node = stack_a->begin;
    while (current_node != NULL)
    {
        current_node->combined_moves = ft_evaluate_combined_moves(stack_a, stack_b, current_node);
        current_node->direct_moves = ft_evaluate_direct_moves(stack_a, stack_b, current_node);
        ft_select_optimal_strategy(current_node);
        current_node = current_node->next;
    }
}
