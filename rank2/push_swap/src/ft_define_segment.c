/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_segment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:41:47 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/25 10:33:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_partition(int *arr, int low, int high)
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

static int	ft_quick_select(int *arr, int low, int high, int k)
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

void	ft_fill_arr(t_stack *stack, int **arr)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		(*arr)[i] = current->nb;
		current = current->next;
		i++;
	}
}

int	*ft_find_pivots(t_stack *stack, int size, int *pivots)
{
	int	i;
	int	*values;

	i = -1;
	values = (int *)malloc(size * sizeof(int));
	if (!values)
		return (NULL);
	ft_fill_arr(stack, &values);
	if (size > 100)
	{
		pivots[0] = ft_quick_select(values, 0, size - 1, size / 5);
		pivots[1] = ft_quick_select(values, 0, size - 1, (2 * size) / 5);
		pivots[2] = ft_quick_select(values, 0, size - 1, (3 * size) / 5);
		pivots[3] = ft_quick_select(values, 0, size - 1, (4 * size) / 5);
	}
	else
	{
		while (++i <= 3)
			pivots[i] = 0;
	}
	free(values);
	return (pivots);
}

void	ft_assign_segment(t_stack **a, int pivot[3])
{
	int		value;
	t_stack	*stack_a;

	stack_a = *a;
	value = stack_a->nb;
	while (stack_a)
	{
		value = stack_a->nb;
		if (value <= pivot[0])
			stack_a->segment = 1;
		else if (value <= pivot[1])
			stack_a->segment = 2;
		else if (value <= pivot[2])
			stack_a->segment = 3;
		else if (value <= pivot[3])
			stack_a->segment = 4;
		else
			stack_a->segment = 5;
		stack_a = stack_a->next;
	}
}
