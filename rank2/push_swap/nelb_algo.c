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

//////////////Main function sort_a + sub functions///////////////////
void	sort_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (*b)
	{
		prep_stack_b(b, a);
		cheapest = find_cheapest(*b);
		b_and_target_to_top(b, cheapest, a);
		push_a(b, a);
	}
}

void	prep_stack_b(t_stack **b, t_stack **a)
{
	index_in_stack(a);
	index_in_stack(b);
	find_target_b_in_a(*b, *a);
	target_cost(b, a);
	total_cost(*b, *a);
	set_cheapest_to_null(b);
	get_cheapest(b);
}

t_stack	*find_cheapest(t_stack *a)
{
	t_stack	*stack_a;

	stack_a = a;
	if (!stack_a)
		return (NULL);
	while (stack_a)
	{
		if (stack_a->is_cheapest)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}

void	b_and_target_to_top(t_stack **b, t_stack *cheapest, t_stack **a)
{
	int	cost_b;
	int	target_cost;

	target_cost = calculate_node_cost(cheapest->target_node, ft_stack_size(*a));
	cost_b = calculate_node_cost(cheapest, ft_stack_size(*b));
	if ((cheapest->is_in_top && cheapest->target_node->is_in_top)
		|| (!cheapest->is_in_top && !cheapest->target_node->is_in_top))
		both_to_top(b, cheapest, a, cost_b);
	else
	{
		if (cheapest->is_in_top)
		{
			single_rotate(a, target_cost, rev_rotate_a);
			single_rotate(b, cost_b, rotate_b);
		}
		else
		{
			single_rotate(a, target_cost, rotate_a);
			single_rotate(b, cost_b, rev_rotate_b);
		}
	}
}

void	push_a(t_stack **b, t_stack **a)
{
	push_top_to_stack(b, a);
	ft_printf("pa\n");
}


/////////SUB FUNCTIONS OF prep_stack_b

void	prep_stack_b(t_stack **b, t_stack **a)
{
	index_in_stack(a);
	index_in_stack(b);
	find_target_b_in_a(*b, *a);
	target_cost(b, a);
	total_cost(*b, *a);
	set_cheapest_to_null(b);
	get_cheapest(b);
}

void	find_target_b_in_a(t_stack *b, t_stack *a)
{
	t_stack	*stack_a;
	t_stack	*target;
	int		target_nb;

	while (b)
	{
		target = NULL;
		target_nb = INT_MAX;
		stack_a = a;
		while (stack_a)
		{
			if (stack_a->nb > b->nb && stack_a->nb < target_nb)
			{
				target_nb = stack_a->nb;
				target = stack_a;
			}
			stack_a = stack_a->next;
		}
		if (target_nb == INT_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

t_stack	*find_min(t_stack *lst)
{
	t_stack	*min_node;
	int		min;

	min_node = lst;
	min = INT_MAX;
	while (lst)
	{
		if (lst->nb < min)
		{
			min_node = lst;
			min = lst->nb;
		}
		lst = lst->next;
	}
	return (min_node);
}

void	target_cost(t_stack **a, t_stack **b)
{
	t_stack	*stack_a;
	int		stack_len;

	stack_a = *a;
	stack_len = ft_stack_size(*b);
	while (stack_a)
	{
		if (stack_a->target_node->is_in_top)
			stack_a->target_cost = stack_a->target_node->index;
		else
			stack_a->target_cost = stack_len - stack_a->target_node->index;
		stack_a = stack_a->next;
	}
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
 
void	get_cheapest(t_stack **a)
{
	t_stack	*stack_a;
	t_stack	*cheapest;
	int		cheapest_cost;

	cheapest = NULL;
	cheapest_cost = INT_MAX;
	stack_a = *a;
	while (stack_a)
	{
		if (stack_a->total_cost < cheapest_cost)
		{
			cheapest_cost = stack_a->total_cost;
			cheapest = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (cheapest)
		cheapest->is_cheapest = 1;
}

/////////SUB FUNCTIONS OF b_and_target_to_top/////////////////

int	calculate_node_cost(t_stack *node, int stack_length)
{
	if (node->is_in_top)
		return (node->index);
	else
		return (stack_length - node->index);
}

void	both_to_top(t_stack **b, t_stack *cheapest, t_stack **a, int cost_b)
{
	int	target_cost;

	target_cost = calculate_node_cost(cheapest->target_node, ft_stack_size(*a));
	if (cheapest->is_in_top)
		double_rotate(a, b, ft_min(cost_b, target_cost), rr);
	else
		double_rotate(a, b, ft_min(cost_b, target_cost), rrr);
	if (cost_b < target_cost)
	{
		if (cheapest->is_in_top)
			single_rotate(a, target_cost - cost_b, rotate_a);
		else
			single_rotate(a, target_cost - cost_b, rev_rotate_a);
	}
	else if (cost_b > target_cost)
	{
		if (cheapest->is_in_top)
			single_rotate(b, cost_b - target_cost, rotate_b);
		else
			single_rotate(b, cost_b - target_cost, rev_rotate_b);
	}
}

