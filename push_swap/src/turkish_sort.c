/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/09 20:08:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

t_dcnode    *ft_ischeapest(t_dclst *stack_a)
{
    t_dcnode *current = stack_a->begin;
    t_dcnode *cheapest_node = NULL;
    int lowest_cost = INT_MAX;

    while (current != NULL)
    {
        if (current->push_cost < lowest_cost)
        {
            lowest_cost = current->push_cost;
            cheapest_node = current;
        }
        current = current->next;
    }
    ft_printf("Cheapest value : %i\n", cheapest_node->value);
    return cheapest_node;
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
    ft_printf("Moves %i\n", stack_a->moves + stack_b->moves);
}
