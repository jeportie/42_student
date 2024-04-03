/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/03 19:43:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void ft_ischeapest(t_dclst *stack_a)
{
    t_dcnode *current = stack_a->begin;
    t_dcnode *cheapest_node = NULL;
    int lowest_cost = INT_MAX;

    // Reset the cheapest flag for all nodes before finding the new cheapest.
    for (t_dcnode *tmp = stack_a->begin; tmp != NULL; tmp = tmp->next) {
        tmp->cheapest = false;
    }

    while (current != NULL)
    {
        // If a node with push_cost of 0 is found, it's automatically the cheapest.
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

    // Mark the cheapest node.
    if (cheapest_node != NULL)
        cheapest_node->cheapest = true;
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
    if (stack_a->length > 5)
    {
    	while (stack_a->length > 3)
    	{
    		ft_define_target(stack_a, stack_b);
    		ft_isabove_median(stack_a, stack_b);
    		ft_calculate_push_cost(stack_a, stack_b);
     //       ft_printf("push cost : %i\n", stack_a->begin->push_cost);
     //       ft_printf("comb moves : %i\n", stack_a->begin->combined_moves);
     //       ft_printf("a moves : %i\n", stack_a->begin->moves_a);
     //       ft_printf("b moves : %i\n", stack_a->begin->moves_b);
    		ft_ischeapest(stack_a);
    		ft_push_to_target(stack_a, stack_b);
    		ft_init_push_cost(stack_a);
    	}
    }
	ft_sort_three(stack_a);
	ft_print_stack(stack_b, 'b');
	ft_back_to_stack_a(stack_a, stack_b);
	ft_fine_tune(stack_a);
}
