/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:31:39 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 12:31:41 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_three_a(t_stack **lst)
{
	t_stack	*max;

	max = ft_find_max(*lst);
	if (!*lst || ft_stack_size(*lst) != 3)
		return ;
	if (*lst == max)
		ra(lst);
	else if ((*lst)->next == max)
		rra(lst);
	if (!ft_is_sorted(*lst))
		sa(lst);
}

int	ft_is_sorted(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_is_sorted_b(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->nb < lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_stack	*ft_find_max(t_stack *lst)
{
	t_stack	*max_node;
	int		max;

	max_node = lst;
	max = INT_MIN;
	while (lst)
	{
		if (lst->nb > max)
		{
			max_node = lst;
			max = lst->nb;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_stack	*ft_find_min(t_stack *lst)
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
