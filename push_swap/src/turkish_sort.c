/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/08 16:46:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void    ft_define_cheapest(t_dcnode *node, t_dclst *stack)
{
    t_dcnode    *current;

    current = stack->begin;
    while (current)
    {
        if (!current->cheapest)
            current->to_cheapest = node;
        current = current->next;
    }
}

void    ft_ischeapest(t_dclst *stack_a)
{
    t_dcnode *current = stack_a->begin;
    t_dcnode *cheapest_node = NULL;
    int lowest_cost = INT_MAX;
    for (t_dcnode *tmp = stack_a->begin; tmp != NULL; tmp = tmp->next) {
        tmp->cheapest = false;
    }
    while (current != NULL)
    {
        if (current->push_cost == 0)
        {
            cheapest_node = current;
            break; // No need to continue searching.
        }
        else if (current->push_cost < lowest_cost)
        {
            lowest_cost = current->push_cost;
            cheapest_node = current;
        }
        current = current->next;
    }
    if (cheapest_node != NULL)
        cheapest_node->cheapest = true;
    ft_define_cheapest(cheapest_node, stack_a);
}

void	turkish_sort(t_dclst *stack_a, t_dclst *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->length == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	ft_push_initial_numbers(stack_a, stack_b);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
    if (stack_a->length > 5)
    {
    	while (stack_a->length > 3)
    	{
            ft_printf("top stack_a : %i\n", stack_a->begin->value);
    		ft_define_target(stack_a, stack_b);
    		ft_isabove_median(stack_a, stack_b);
    		ft_calculate_push_cost(stack_a, stack_b);
    		ft_ischeapest(stack_a);
    		ft_push_to_target(stack_a, stack_b);
    		ft_init_push_cost(stack_a);
    		ft_print_stack(stack_a, 'a');
	    	ft_print_stack(stack_b, 'b');
    	}
    }
	ft_sort_three(stack_a);
	ft_print_stack(stack_b, 'b');
	ft_back_to_stack_a(stack_a, stack_b);
	ft_fine_tune(stack_a);
}
