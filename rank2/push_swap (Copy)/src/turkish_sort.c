/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/23 20:53:02 by jeportie         ###   ########.fr       */
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

void	turkish_sort(t_dclst *stack_a, t_dclst *stack_b)
{
	int	*pivots;

	if (!stack_a || !stack_b || ft_is_sort(stack_a))
		return ;
	pivots = ft_find_pivots(stack_a, stack_a->length);
	ft_segment_stack(stack_a, pivots);
	free(pivots);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	ft_sort_b(stack_a, stack_b);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	ft_sort_three(stack_a);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	ft_back_to_stack_a(stack_a, stack_b);
//	ft_fine_tune(stack_a);
}
