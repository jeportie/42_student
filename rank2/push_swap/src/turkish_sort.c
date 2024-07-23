/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/23 23:51:15 by jeportie         ###   ########.fr       */
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
		pivot[1] = ft_quick_select(values, 0, size - 1, (2 * size) / 5);
		pivot[2] = ft_quick_select(values, 0, size - 1, (3 * size) / 5);
		pivot[3] = ft_quick_select(values, 0, size - 1, (4 * size) / 5);
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
	while (stack_a)
	{

		if (!current)
			return ;
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

int	ft_min(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_b);
	return (cost_a);
}

int ft_calculate_node_cost(t_dcnode *node, int stack_length)
{
	if (!node)
		return (-1);
    if (node->above_median)
        return (node->index);
    else
        return (stack_length - node->index);
}

void ft_double_rotate(t_dclst *stack_a, t_dclst *stack_b, int count,
        void (*move)(t_dclst *, t_dclst *))
{
    int i;

    i = 0;
    while (i < count)
    {
        move(stack_a, stack_b);
        i++;
    }
}

void ft_single_rotate(t_dclst *stack, int count, void (*move)(t_dclst *, bool))
{
    int i;

    i = 0;
    while (i < count)
    {
        move(stack, true);
        i++;
    }
}

void ft_both_to_top(t_dclst *stack_a, t_dclst *stack_b, t_dcnode *cheapest, int cost_b)
{
    int target_cost;

    target_cost = ft_calculate_node_cost(cheapest->target, stack_a->length);
    if (cheapest->above_median)
        ft_double_rotate(stack_a, stack_b, ft_min(cost_b, target_cost), rr);
    else
        ft_double_rotate(stack_a, stack_b, ft_min(cost_b, target_cost), rrr);
    if (cost_b < target_cost)
    {
        if (cheapest->above_median)
            ft_single_rotate(stack_a, target_cost - cost_b, ra);
        else
            ft_single_rotate(stack_a, target_cost - cost_b, rra);
    }
    else if (cost_b > target_cost)
    {
        if (cheapest->above_median)
            ft_single_rotate(stack_b, cost_b - target_cost, rb);
        else
            ft_single_rotate(stack_b, cost_b - target_cost, rrb);
    }
}


void ft_rotate_b_and_target_to_top(t_dclst *stack_a, t_dclst *stack_b, t_dcnode *cheapest)
{
    int cost_b;
    int target_cost;

    target_cost = ft_calculate_node_cost(cheapest->target, stack_a->length);
    cost_b = ft_calculate_node_cost(cheapest, stack_b->length);
    if ((cheapest->above_median && cheapest->target->above_median)
        || (!cheapest->above_median && !cheapest->target->above_median))
        ft_both_to_top(stack_a, stack_b, cheapest, cost_b);
    else
    {
        if (cheapest->above_median)
        {
            ft_single_rotate(stack_a, target_cost, rra);
            ft_single_rotate(stack_b, cost_b, rb);
        }
        else
        {
            ft_single_rotate(stack_a, target_cost, ra);
            ft_single_rotate(stack_b, cost_b, rrb);
        }
    }
}

t_dcnode *ft_find_cheapest(t_dcnode *node)
{
    t_dcnode *cheapest;

    cheapest = node;
    if (!cheapest)
        return (NULL);
    while (cheapest)
    {
        if (cheapest->cheapest)
            return (cheapest);
        cheapest = cheapest->next;
    }
    return (NULL);
}

t_dcnode *ft_find_min(t_dcnode *lst)
{
    t_dcnode *min_node;
    long min_value;

    min_node = lst;
    min_value = LONG_MAX;
    while (lst)
    {
        if (lst->value < min_value)
        {
            min_node = lst;
            min_value = lst->value;
        }
        lst = lst->next;
    }
    return (min_node);
}

void	ft_find_target(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode *current;
    t_dcnode *stack_a_node;
    t_dcnode *target;
    long target_value;

    current = stack_b->begin;
    while (current)
    {
        target = stack_a->begin;
        target_value = LONG_MAX;
        stack_a_node = stack_a->begin;
        while (stack_a_node)
        {
            if (stack_a_node->value > current->value && stack_a_node->value < target_value)
            {
                target_value = stack_a_node->value;
                target = stack_a_node;
            }
            stack_a_node = stack_a_node->next;
        }
        if (target_value == LONG_MAX)
            current->target = ft_find_min(stack_a->begin);
        else
            current->target = target;
        current = current->next;
    }
}

void ft_calculate_total_cost(t_dclst *stack_b, t_dclst *stack_a)
{
    t_dcnode *node_a;
    int cost_a;
    int cost_b;

    node_a = stack_a->begin;
    while (node_a)
    {
        cost_a = ft_calculate_node_cost(node_a, stack_a->length);
        cost_b = ft_calculate_node_cost(node_a->target, stack_b->length);
        if (node_a->above_median == node_a->target->above_median)
            node_a->combined_moves = cost_a + cost_b - ft_min(cost_a, cost_b);
        else
            node_a->combined_moves = cost_a + cost_b;
        node_a = node_a->next;
    }
}

void ft_calculate_target_cost(t_dclst *stack_b, t_dclst *stack_a)
{
    t_dcnode *node_a;

    node_a = stack_a->begin;
    while (node_a)
    {
        if (node_a->target->above_median)
            node_a->moves_to_top = node_a->target->index;
        else
            node_a->moves_to_top = stack_b->length - node_a->target->index;
        node_a = node_a->next;
    }
}

void ft_set_cheapest_to_null(t_dclst *stack)
{
    t_dcnode *node;

    node = stack->begin;
    while (node)
    {
        node->cheapest = false;
        node = node->next;
    }
}

void ft_mark_cheapest(t_dclst *stack)
{
    t_dcnode *node;
    t_dcnode *cheapest;
    int cheapest_cost;

    cheapest = NULL;
    cheapest_cost = INT_MAX;
    node = stack->begin;
    while (node)
    {
        if (node->combined_moves < cheapest_cost)
        {
            cheapest_cost = node->combined_moves;
            cheapest = node;
        }
        node = node->next;
    }
    if (cheapest)
        cheapest->cheapest = true;
}

void	ft_prep_b(t_dclst *stack_a, t_dclst *stack_b)
{
	ft_isabove_median(stack_a, stack_b);
	ft_actualise_indexes(stack_a, stack_b);
	ft_find_target(stack_a, stack_b);
	ft_calculate_target_cost(stack_a, stack_b);
	ft_calculate_total_cost(stack_a, stack_b);
	ft_set_cheapest_to_null(stack_b);
	ft_mark_cheapest(stack_b);
}

void	ft_sort_a(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*cheapest;

	while (stack_b->begin)
	{
		ft_prep_b(stack_a, stack_b);
		cheapest = ft_find_cheapest(stack_b->begin);
		ft_rotate_b_and_target_to_top(stack_a, stack_b, cheapest);
		pa(stack_a, stack_b);
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
//	ft_print_stack(stack_a, 'a');
//	ft_print_stack(stack_b, 'b');
	ft_sort_b(stack_a, stack_b);
//	ft_print_stack(stack_a, 'a');
//	ft_print_stack(stack_b, 'b');
	ft_sort_three(stack_a);
//	ft_print_stack(stack_a, 'a');
//	ft_print_stack(stack_b, 'b');
//	ft_back_to_stack_a(stack_a, stack_b);
	ft_sort_a(stack_a, stack_b);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
//	ft_fine_tune(stack_a);
}
