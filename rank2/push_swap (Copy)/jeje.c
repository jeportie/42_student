///////////////MAIN FUNCTION AND SUBFUCTIONS /////////

void ft_back_to_stack_a(t_dclst *stack_a, t_dclst *stack_b)
{
    while (stack_b->length)
	{
        ft_actualise_indexes(stack_a, stack_b);
        ft_isabove_median(stack_a, stack_b);
        ft_define_target(stack_b, stack_a);
        ft_calculate_push_cost(stack_a, stack_b);
        ft_push_to_target(stack_a, stack_b);
		ft_print_stack(stack_a, 'a');
		ft_print_stack(stack_b, 'b');
    }
}

void	ft_actualise_indexes(t_dclst *stack_a, t_dclst *stack_b)
{
	ft_define_index(stack_a);
	ft_define_index(stack_b);
}

void	ft_isabove_median(t_dclst *stack_a, t_dclst *stack_b)
{
	ft_mark_above_median(stack_a);
	ft_mark_above_median(stack_b);
}

void	ft_define_target(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_b;

	if (!stack_a || !stack_b)
		return ;
	current_b = stack_b->begin;
	while (current_b)
	{
		current_b->target = ft_closest_greater_number(current_b, stack_a);
		current_b = current_b->next;
	}
}

void	ft_calculate_push_cost(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_node;
	int			i;

	i = 1;
	current_node = stack_a->begin;
	while (current_node)
	{
		ft_evaluate_combined_moves(stack_a, stack_b, current_node);
		ft_evaluate_direct_moves(stack_a, stack_b, current_node);
		ft_select_optimal_strategy(current_node);
		i++;
		current_node = current_node->next;
	}
}

void	ft_push_to_target(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*cheapest_node;

	cheapest_node = ft_ischeapest(stack_b);
	if (!cheapest_node)
		return ;
	if (cheapest_node && cheapest_node->target && cheapest_node->above_median == cheapest_node->target->above_median)
	{
		ft_execute_combined_moves(stack_a, stack_b, cheapest_node);
		ft_adjust_remaining_moves(stack_a, stack_b, cheapest_node);
	}
	else
		ft_execute_direct_moves(stack_a, stack_b, cheapest_node);
	pa(stack_a, stack_b);
}

//////////// UTILITIES FUNCTIONS for index and median///////////
 
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

//////////// Helper FUnction for ft_define target///////////

t_dcnode	*ft_closest_greater_number(t_dcnode *node_b, t_dclst *stack_a)
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
	ft_helpera(current_a, target_a, min_value, stack_a);
	return (target_a);
}


static void	ft_helpera(t_dcnode *current_a, t_dcnode *target_a, long min_value,
		t_dclst *stack_a)
{
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
}

////////////////// calculate puish cost //////////////////// 

int	ft_moves_to_top(t_dclst *stack, t_dcnode *node)
{
	int	moves;

	moves = 0;
	if (stack && node && stack->end)
	{
		ft_define_index(stack);
		ft_mark_above_median(stack);
		if (node->above_median)
			moves = node->index - 1;
		else
			moves = stack->end->index - node->index + 1;
	}
	return (moves);
}


void	ft_calculate_push_cost(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*current_node;
	int			i;

	i = 1;
	current_node = stack_a->begin;
	while (current_node)
	{
		ft_evaluate_combined_moves(stack_a, stack_b, current_node);
		ft_evaluate_direct_moves(stack_a, stack_b, current_node);
		ft_select_optimal_strategy(current_node);
		i++;
		current_node = current_node->next;
	}
}
