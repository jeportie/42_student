/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:30:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/16 18:25:49 by jeportie         ###   ########.fr       */
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

void	ft_mark_above_median(t_dclst *stack)
{
	int			median_position;
	int			position;
	t_dcnode	*current;

	median_position = (stack->length + 1) / 2;
	position = 1;
	current = stack->begin;
	while (current)
	{
		if (position <= median_position)
			current->above_median = true;
		else 
			current->above_median = false;
		current = current->next;
		position++;
	}
}

void	ft_isabove_median(t_dclst *stack_a, t_dclst *stack_b)
{
	ft_mark_above_median(stack_a);
	ft_mark_above_median(stack_b);
}

void	ft_define_index(t_dclst *stack)
{
	t_dcnode	*current;
	int			i;

	current = stack->begin;
	i = 1;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void	ft_actualise_indexes(t_dclst *stack_a, t_dclst *stack_b)
{
	ft_define_index(stack_a);
	ft_define_index(stack_b);
}
