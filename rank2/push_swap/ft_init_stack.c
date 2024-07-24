/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:16:26 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 12:18:15 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

void	ft_init_stack(t_stack **stack_a, char *joined_args)
{
	char	**split_args;
	int		i;

	split_args = ft_split(joined_args, ' ');
	i = 0;
	while (split_args[i])
	{
		ft_stackadd_back(stack_a, ft_stacknew(ft_atoi(split_args[i])));
		i++;
	}
	free_malloc(split_args, ft_count_words(joined_args, ' '));
}

t_stack	*ft_init_b(void)
{
	return (NULL);
}

void	ft_validate_and_init_stack(t_stack **a, char *joined_args)
{
	if (!joined_args || !ft_is_valid_number_string(joined_args))
	{
		free(joined_args);
		ft_print_error(a);
	}
	ft_init_stack(a, joined_args);
}

void	ft_check_dup_and_sort(t_stack **a, t_stack **b)
{
	if (ft_check_duplicate_in_stack(*a) || ft_is_not_int(*a))
		ft_print_error(a);
	if (!ft_is_sorted(*a))
	{
		if (ft_stack_size(*a) == 3)
			ft_sort_three_a(a);
		else
			ft_sort_stack(a, b);
	}
}

void	ft_free_stack(t_stack **lst)
{
	t_stack	*stack;
	t_stack	*tmp;

	stack = *lst;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
}
