/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:30:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/16 15:01:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	ft_push_initial_numbers(t_dclst *stack_a, t_dclst *stack_b)
{
	if (stack_a->length == 4)
	{
		pb(stack_a, stack_b);	
		return ;
	}
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	ft_isabove_median(t_dclst *stack_a, t_dclst *stack_b)
{
	ft_mark_above_median(stack_a);
	ft_mark_above_median(stack_b);
}

void	ft_actualise_indexes(t_dclst *stack_a, t_dclst *stack_b)
{
	ft_define_index(stack_a);
	ft_define_index(stack_b);
}

t_dcnode    *ft_ischeapest(t_dclst *stack_a)
{
    t_dcnode *current = stack_a->begin;
    t_dcnode *cheapest_node = NULL;
    int lowest_cost = INT_MAX;

    while (current != NULL)
    {
        ft_printf("Node : %i -> push cost : %i\n", current->value, current->push_cost);
        ft_printf("Target : %i Above med : %i\n", current->target->value, current->target->above_median);
        if (current->push_cost < lowest_cost)
        {
            lowest_cost = current->push_cost;
            cheapest_node = current;
        }
        current = current->next;
    }
    ft_printf("cheapest : %i\n", cheapest_node->value);
    return cheapest_node;
}
