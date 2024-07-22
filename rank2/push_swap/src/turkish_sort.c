/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/22 15:32:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	ft_swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

int	ft_partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int	ft_quick_select(int *arr, int low, int high, int k)
{
	int	index_pivot;

	if (low <= high)
	{
		index_pivot = ft_partition(arr, low, high);
		if (index_pivot == k)
			return (arr[index_pivot]);
		else if (index_pivot < k)
			return (ft_quick_select(arr, index_pivot + 1, high, k));
		else
			return (ft_quick_select(arr, low, index_pivot - 1, k));
	}
	return (-1);
}

int	*ft_find_pivots(t_dclst *stack, int size)
{
	int			*values;
	int			*pivot;
	t_dcnode	*current;
	int			i;

	values = malloc(size * sizeof(int));
	if (!values)
		return (0);
	pivot = malloc(4 * sizeof(int));
	if (!pivot)
	{
		free(values);
		return (0);
	}
	current = stack->begin;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current->segment = 5;
		current = current->next;
	}
	if (size > 100)
	{
		pivot[0] = ft_quick_select(values, 0, size - 1, size / 5);
		ft_printf("pivot[0] : %i\n", pivot[0]);
		pivot[1] = ft_quick_select(values, 0, size - 1, (2 * size) / 5);
		ft_printf("pivot[1] : %i\n", pivot[1]);
		pivot[2] = ft_quick_select(values, 0, size - 1, (3 * size) / 5);
		ft_printf("pivot[2] : %i\n", pivot[2]);
		pivot[3] = ft_quick_select(values, 0, size - 1, (4 * size) / 5);
		ft_printf("pivot[3] : %i\n", pivot[3]);
	}
	else
	{
		i = 0;
		while (i < 4)
		{
			pivot[i] = 0;
			i++;
		}
	}
	free(values);
	return (pivot);
}

void	ft_segment_stack(t_dclst *stack_a, int *pivot)
{
	t_dcnode	*current;

	current = stack_a->begin;
	current->segment = 0;
	if (!pivot[0] && !pivot[1] && !pivot[2] && !pivot[3])
	{
		return ;
	}
	while (stack_a)
	{
		if (current->value <= pivot[0])
			current->segment = 1;
		else if (current->value <= pivot[1])
			current->segment = 2;
		else if (current->value <= pivot[2])
			current->segment = 3;
		else if (current->value <= pivot[3])
			current->segment = 4;
		else
			current->segment = 5;
		current = current->next;
	}
}

int	ft_calculate_node_cost(t_dclst *stack, t_dcnode *node)
{
	int	moves_to_top;

	moves_to_top = ft_moves_to_top(stack, node);
	if (node->above_median)
		return (moves_to_top);
	else
		return (stack->length - moves_to_top);
}

void	ft_calculate_cost(t_dclst *stack_a)
{
	t_dcnode	*current;

	current = stack_a->begin;
	while (current)
	{
		current->push_cost = ft_calculate_node_cost(stack_a, current);
		current = current->next;
	}
}

void	ft_node_to_top(t_dclst *stack, t_dcnode *node)
{
	while (stack->begin	!= node)
	{
		if (node->above_median)
			ra(stack, true);
		else
			rra(stack, true);
	}
}

void	ft_push_to_b(t_dclst *stack_a, t_dclst *stack_b, int seg)
{
	t_dcnode	*current;

	current = stack_a->begin;
	if (current->segment == seg && current->cheapest)
	{
		ft_node_to_top(stack_a, current);
		pb(stack_a, stack_b);
		current = stack_a->begin;
	}
	else
		current = current->next;
}

void	ft_get_segment_cheapest(t_dclst *stack, int seg)
{
	t_dcnode	*current;
	t_dcnode	*cheapest;
	int			cheapest_cost;

	current = stack->begin;
	cheapest = NULL;
	cheapest_cost = INT_MAX;

	while (current)
	{
		if (current->segment == seg && current->push_cost < cheapest_cost)
		{
			cheapest_cost = current->push_cost;
			cheapest = current;
		}
		current = current->next;
	}
	if (cheapest)
		cheapest->cheapest = true;
}

void	ft_sort_b(t_dclst *stack_a, t_dclst *stack_b)
{
	int		seg;

	ft_isabove_median(stack_a, stack_b);
	seg = 0;
	while (seg <= 5)
	{
		while (stack_a->length > 3)
		{
			ft_actualise_indexes(stack_a,stack_b);
			ft_calculate_cost(stack_a);
			ft_get_segment_cheapest(stack_a, seg);
			ft_push_to_b(stack_a, stack_b, seg);
		}
		seg++;
	}
}

void	turkish_sort(t_dclst *stack_a, t_dclst *stack_b)
{
	int	*pivots;

	if (!stack_a || !stack_b || ft_is_sort(stack_a))
		return ;
	pivots = ft_find_pivots(stack_a, stack_a->length);
	ft_segment_stack(stack_a, pivots);
	free(pivots);
//	ft_push_initial_numbers(stack_a, stack_b);
//	if (stack_a->length > 5)
//	{
//		while (stack_a->length > 3)
//		{
//			ft_define_target(stack_a, stack_b);
//			ft_isabove_median(stack_a, stack_b);
//			ft_calculate_push_cost(stack_a, stack_b);
//			ft_push_to_target(stack_a, stack_b);
//		}
//	}
	ft_sort_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_back_to_stack_a(stack_a, stack_b);
	ft_fine_tune(stack_a);
}
