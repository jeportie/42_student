/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nelb_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:26:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/19 10:18:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
	long			nb;
	int				index;
	int				is_in_top;
	int				total_cost;
	int				target_cost;
	int				segment;
	int				is_cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	

int	ft_stack_size(t_stack *lst)
{
	int	node;

	node = 0;
	while (lst)
	{
		lst = lst->next;
		node++;
	}
	return (node);
}

void	sort_b(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		size;
	int		seg;

	seg = -1;
	size = ft_stack_size(*a);
	prep_stack_a(a);
	while (++seg <= 5)
	{
		current = *a;
		while (current && size > 3)
		{
			assign_cost_in_a(a);
			get_cheapest_by_segment(a, seg);
			if (current->segment == seg && current->is_cheapest)
			{
				node_to_top(a, current);
				push_b(a, b);
				current = *a;
				size--;
			}
			else
				current = current->next;
		}
	}
}

void	prep_stack_a(t_stack **a)
{
	int	*pivots;
	int	size;

	size = ft_stack_size(*a);
	pivots = malloc(4 * sizeof(int));
	if (!pivots)
		return ;
	pivots = find_pivots(*a, size, pivots);
	set_cheapest_to_null(a);
	assign_segment(a, pivots);
	free(pivots);
}

int	*find_pivots(t_stack *stack, int size, int *pivots)
{
	int	i;
	int	*values;

	i = -1;
	values = (int *)malloc(size * sizeof(int));
	if (!values)
		return (NULL);
	fill_arr(stack, &values);
	if (size > 100)
	{
		pivots[0] = quick_select(values, 0, size - 1, size / 5);
		pivots[1] = quick_select(values, 0, size - 1, (2 * size) / 5);
		pivots[2] = quick_select(values, 0, size - 1, (3 * size) / 5);
		pivots[3] = quick_select(values, 0, size - 1, (4 * size) / 5);
	}
	else
	{
		while (++i <= 3)
			pivots[i] = 0;
	}
	free(values);
	return (pivots);
}

int	quick_select(int *arr, int low, int high, int k)
{
	int	index_pivot;

	if (low <= high)
	{
		index_pivot = partition(arr, low, high);
		if (index_pivot == k)
			return (arr[index_pivot]);
		else if (index_pivot < k)
			return (quick_select(arr, index_pivot + 1, high, k));
		else
			return (quick_select(arr, low, index_pivot - 1, k));
	}
	return (-1);
}

int	partition(int *arr, int low, int high)
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

void	set_cheapest_to_null(t_stack **lst)
{
	t_stack	*stack;

	stack = *lst;
	while (stack)
	{
		stack->is_cheapest = 0;
		stack = stack->next;
	}
}

void	assign_segment(t_stack **a, int *pivot)
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

void	assign_cost_in_a(t_stack **a)
{
	t_stack	*stack_a;
	int		stack_len;

	stack_a = *a;
	stack_len = ft_stack_size(stack_a);
	index_in_stack(a);
	while (stack_a)
	{
		stack_a->total_cost = calculate_node_cost(stack_a, stack_len);
		stack_a = stack_a->next;
	}
}

void	index_in_stack(t_stack **lst)
{
	int		i;
	int		mid;
	t_stack	*stack;

	i = 0;
	stack = *lst;
	mid = mid_stack(stack);
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->is_in_top = 1;
		else
			stack->is_in_top = 0;
		stack = stack->next;
		i++;
	}
}

int	calculate_node_cost(t_stack *node, int stack_length)
{
	if (node->is_in_top)
		return (node->index);
	else
		return (stack_length - node->index);
}

void	get_cheapest_by_segment(t_stack **a, int seg)
{
	t_stack	*stack_a;
	t_stack	*cheapest;
	int		cheapest_cost;

	cheapest = NULL;
	cheapest_cost = INT_MAX;
	stack_a = *a;
	while (stack_a)
	{
		if (stack_a->total_cost < cheapest_cost && stack_a->segment == seg)
		{
			cheapest_cost = stack_a->total_cost;
			cheapest = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (cheapest)
		cheapest->is_cheapest = 1;
}

void	node_to_top(t_stack **a, t_stack *node)
{
	int	cost_a;
	int	stack_len;

	stack_len = ft_stack_size(*a);
	cost_a = calculate_node_cost(node, stack_len);
	if (node->is_in_top)
		single_rotate(a, cost_a, rotate_a);
	else
		single_rotate(a, cost_a, rev_rotate_a);
}

void	single_rotate(t_stack **stack, int count, void (*move)(t_stack **))
{
	int	i;

	i = 0;
	while (i < count)
	{
		move(stack);
		i++;
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	push_top_to_stack(a, b);
	ft_printf("pb\n");
}

void	push_top_to_stack(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src || !dst)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (!dst)
	{
		*dst = tmp;
		(*dst)->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		*dst = tmp;
	}
}
