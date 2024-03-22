/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:15:58 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 18:16:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_to_stack(t_dclst *stack, long value)
{
	t_dcnode	*new_node;

	new_node = (t_dcnode *)malloc(sizeof(t_dcnode));
	if (!new_node)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	new_node->value = value;
	if (!stack->begin)
	{
		stack->begin = new_node;
		stack->end = new_node;
		new_node->next = NULL;
		new_node->back = NULL;
	}
	else
	{
		new_node->next = stack->begin;
		stack->begin->back = new_node;
		new_node->back = NULL;
		stack->begin = new_node;
	}
	stack->length += 1;
}
