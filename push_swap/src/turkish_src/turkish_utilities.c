/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:30:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/04 22:10:36 by jeportie         ###   ########.fr       */
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

void	ft_init_push_cost(t_dclst *stack_a)
{
	t_dcnode	*current_a;

	current_a = stack_a->begin;
	while (current_a)
	{
		current_a->push_cost = 0;
		current_a = current_a->next;
	}
}
