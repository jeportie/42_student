/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/01 21:07:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

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
		ft_push_to_target(stack_a, stack_b);
		ft_init_push_cost(stack_a);
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

int	ft_calculate_moves_to_top(t_dclst *stack, t_dcnode *node)
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

	current_a = stack_a->begin;
	while (current_a)
	{
		current_a->moves_a = ft_calculate_moves_to_top(stack_a, current_a);
		current_a->moves_b = ft_calculate_moves_to_top(stack_b, current_a->target);
		if (current_a->above_median == current_a->target->above_median)
		{
			if (current_a->moves_a < current_a->moves_b)
				current_a->combined_moves = current_a->moves_a;
			else
				current_a->combined_moves = current_a->moves_b;
			current_a->remaining_moves = current_a->moves_a - current_a->moves_b;
			current_a->push_cost = current_a->combined_moves + (int)ft_labs((long)current_a->remaining_moves);
		}
		else
			current_a->push_cost = current_a->moves_a + current_a->moves_b;
		current_a = current_a->next;
	}
}

void	ft_push_to_target(t_dclst *stack_a, t_dclst *stack_b)
{
	int			i;
	t_dcnode	*current;

	current = stack_a->begin;
	while (current)
	{
		if (current->cheapest)
			break;
		current = current->next;
	}
	if (current)
	{
		i = 0;
		while (i < current->combined_moves)
		{
			if (current->above_median)
				rr(stack_a, stack_b);
			else
				rrr(stack_a, stack_b);
			i++;
		}
		i = 0;
		if (current->remaining_moves < 0)
		{
			while (i < (int)ft_labs((long)current->remaining_moves))
			{
				if (current->target->above_median)
					rb(stack_b);
				else
					rrb(stack_b);
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < (int)ft_labs((long)current->remaining_moves))
			{
				if (current->above_median)
					ra(stack_a);
				else
					rra(stack_a);
				i++;
			}
		}
		pb (stack_a, stack_b);
	}
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

t_dcnode*	ft_closest_greater_number(t_dcnode *node_b, t_dclst *stack_a)
{
	t_dcnode	*current_a;
	t_dcnode	*target_a;
	long		min_value;

	current_a = stack_a->begin;
	target_a = NULL;
	min_value = LONG_MAX;
	while (current_a)
	{
		if (current_a->value > node_b->value && current_a->value < min_value)
		{
			target_a = current_a;
			min_value = current_a->value;
		}
		current_a = current_a->next;
	}
	if (!target_a)
	{
		current_a = stack_a->begin;
		while (current_a)
		{
			if (current_a->value < min_value)
			{
				target_a = current_a;
				min_value = current_a->value;
			}
			current_a = current_a->next;
		}
	}
	return (target_a);
}

void	ft_back_to_stack_a(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_b;	
	int			moves;
	int			i;

	current_b = stack_b->begin;
	moves = 0;
	while (current_b)
	{
		ft_actualise_indexes(stack_a, stack_b);
		ft_isabove_median(stack_a, stack_b),
		current_b->target = ft_closest_greater_number(current_b, stack_a);
		moves = ft_calculate_moves_to_top(stack_a, current_b->target);
		i = 0;
		while (i < moves)
		{
			if (current_b->target->above_median)
				ra(stack_a);
			else
				rra(stack_a);
			i++;
		}
		pa(stack_a, stack_b);
	}
}

void	ft_fine_tune(t_dclst *stack_a)
{
	t_dcnode	*current;
	t_dcnode	*min_node;
	long		min_value;
	int			moves;

	ft_define_index(stack_a);
	ft_mark_above_median(stack_a);
	current = stack_a->begin;
	min_value = LONG_MAX;
	min_node = NULL;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_node = current;
		}
		current = current->next;
	}
	moves = ft_calculate_moves_to_top(stack_a, min_node);
	while (moves--)
	{
		if (min_node->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
