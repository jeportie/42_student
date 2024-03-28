/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/28 16:36:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	while (stack_a->length > 3)
	{
		ft_define_target(stack_a, stack_b);
		ft_isabove_median(stack_a, stack_b);
		ft_calculate_push_cost(stack_a, stack_b);
		ft_define_cheapest_node(stack_a);
		ft_push_to_target(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	ft_back_to_stack_a(stack_a, stack_b);
	ft_fine_tune(stack_a);
}

void	ft_topless(t_dclst *stack_a, long top, long middle, long bottom)
{
	if (middle < bottom)
		return;
	if (top < bottom)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else
		ra(stack_a);
}

void	ft_topgreater(t_dclst *stack_a, long top, long middle, long bottom)
{
	if (top < bottom)
		sa(stack_a);
	else if (middle < bottom)
		rra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	ft_sort_three(t_dclst *stack_a)
{
	long	top;
	long	middle;
	long	bottom;

	if (stack_a->length < 3)
		return ;
	top = stack_a->begin->value;
	middle = stack_a->begin->next->value;
	bottom = stack_a->end->value;
	if (top < middle)
		ft_topless(stack_a, top, middle, bottom);
	else
		ft_topgreater(stack_a, top, middle, bottom);
}

void	ft_push_initial_numbers(t_dclst *stack_a, t_dclst *stack_b)
{
	pb(stack_a, stack_b);
	if (stack_a->length == 4)
		return ;
	pb(stack_a, stack_b);
}

t_dcnode*	ft_closest_smaller_number(t_dcnode *node_a, t_dclst *stack_b)
{
	t_dcnode	*current_b;
	t_dcnode	*target_b;
	long		max_value;

	current_b = stack_b->begin;
	target_b = NULL;
	max_value = LONG_MIN;
	while (current_b)
	{
		if (current_b->value < node_a->value && current_b->value > max_value)
		{
			target_b = current_b;
			max_value = current_b->value;
		}
		current_b = current_b->next;
	}
	if (!target_b)
	{
		current_b = stack_b->begin;
		while (current_b)
		{
			if (current_b->value > max_value)
			{
				target_b = current_b;
				max_value = current_b->value;
			}
			current_b = current_b->next;
		}
	}
	return (target_b);
}

void	ft_define_target(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_a;

	if (!stack_a || !stack_b || !stack_b->length)
		return ;
	current_a = stack_a->begin;
	while (current_a)
	{
		current_a->target = ft_closest_smaller_number(current_a, stack_b);
		current_a = current_a->next;
	}
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
		current->above_median = (position <= median_position);
		current = current->next;
		position++;
	}
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

int	calculate_moves_to_top(t_dclst *stack, t_dcnode *node)
{
	int	moves;

	if (node->above_median)
		moves = node->index - 1;
	else
		moves = stack->length - node->index;
	return (moves);
}

void	ft_calculate_push_cost(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_a;
	int			moves_a;
	int			moves_b;
	int			combined_moves;
	int			remaining_moves;

	current_a = stack_a->begin;
	while (current_a)
	{
		moves_a = calculate_moves_to_top(stack_a, current_a);
		moves_b = calculate_moves_to_top(stack_b, current_a->target);
		if (current_a->above_median == current_a->target->above_median)
		{
			combined_moves = 0;
			if (moves_a < moves_b)
				combined_moves = moves_a;
			else
				combined_moves = moves_b;
			remaining_moves = (int)ft_labs((long)moves_a - (long)moves_b);
			current_a->push_cost = combined_moves + remaining_moves;
		}
		else
			current_a->push_cost = moves_a + moves_b;
		current_a = current_a->next;
	}
}
