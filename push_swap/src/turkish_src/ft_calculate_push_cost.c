/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_push_cost.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:04:44 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/16 14:43:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

int	ft_moves_to_top(t_dclst *stack, t_dcnode *node)
{
	int	moves;

    moves = 0;
    if (stack && node && stack->end)
    {
    	ft_define_index(stack);
    	ft_mark_above_median(stack);
    	if (node->above_median)
    		moves = node->index - 1;
    	else
    		moves = stack->end->index - node->index + 1;
    }
	return (moves);
}

void    ft_evaluate_combined_moves(t_dclst *stack_a, t_dclst *stack_b, t_dcnode *node)
{
    int moves_a_to_top;
    int moves_b_to_top;
    int combined_moves;

    combined_moves = INT_MAX;
    moves_a_to_top = ft_moves_to_top(stack_a, node);
    moves_b_to_top = ft_moves_to_top(stack_b, node->target);
    if (node != stack_a->begin /*&& node->above_median == node->target->above_median*/)
    {
        if (moves_a_to_top > moves_b_to_top)
            combined_moves = moves_a_to_top;
        else
            combined_moves = moves_b_to_top;
    }
    else
        combined_moves = 0;
    node->combined_moves = combined_moves;
}

void    ft_evaluate_direct_moves(t_dclst *stack_a, t_dclst *stack_b, t_dcnode *node)
{
    int moves_a_to_top;
    int moves_b_to_top;

    moves_a_to_top = ft_moves_to_top(stack_a, node);
    moves_b_to_top = ft_moves_to_top(stack_b, node->target);
    node->moves_to_top = moves_a_to_top;
    if (node->target)
        node->target->moves_to_top = moves_b_to_top;
}

void ft_select_optimal_strategy(t_dcnode *node)
{
    int remaining_moves;
    int direct_moves;

    remaining_moves = node->moves_to_top - node->target->moves_to_top;
    direct_moves = node->moves_to_top + node->target->moves_to_top;
    if (node->combined_moves + (int)ft_labs(remaining_moves) > direct_moves)
    {
        node->push_cost = node->combined_moves;
        node->remaining_moves = remaining_moves;
    }
    else
        node->push_cost = direct_moves;;
}

void ft_calculate_push_cost(t_dclst *stack_a, t_dclst *stack_b)
{
    t_dcnode    *current_node;
    int i;

    i = 1;
    current_node = stack_a->begin;
    while (current_node)
    {
        ft_evaluate_combined_moves(stack_a, stack_b, current_node);
        ft_evaluate_direct_moves(stack_a, stack_b, current_node);
        ft_select_optimal_strategy(current_node);
        i++;
        current_node = current_node->next;
    }
}
