/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:42:17 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 12:42:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_set_cheapest_to_null(t_stack **lst)
{
	t_stack	*stack;

	stack = *lst;
	while (stack)
	{
		stack->is_cheapest = 0;
		stack = stack->next;
	}
}

t_stack	*ft_init_b(void)
{
	return (NULL);
}

void	ft_print_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		nbr;
	int		first_seen;

	if (!stack)
		return ;
	first_seen = 1;
	tmp = stack;
	while (tmp)
	{
		nbr = tmp->nb;
		if (first_seen == 1)
		{
			ft_printf("%d", nbr);
			first_seen = 0;
		}
		else if (first_seen == 0)
			ft_printf(" %d", nbr);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
