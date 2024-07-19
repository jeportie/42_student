/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/19 08:36:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/push_swap.h"
#include "include/ft_printf.h"

bool	ft_is_sort(t_dclst *stack_a)
{
	t_dcnode	*current;

	if (!stack_a || stack_a->length <= 1)
		return (1);
	current = stack_a->begin;

	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_dclst	*stack_a;
	t_dclst	*stack_b;

	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	if (argc > 1)
	{
		ft_parse_arg(argc, argv, stack_a);
		if (stack_a->length == 3)
			ft_sort_three(stack_a);
		else
			turkish_sort(stack_a, stack_b);
		ft_empty_stack(stack_a);
		ft_empty_stack(stack_b);
	}
	free(stack_a);
	free(stack_b);
	return (0);
}
