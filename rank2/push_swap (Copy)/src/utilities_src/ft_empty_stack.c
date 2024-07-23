/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:40:21 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/19 08:41:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_empty_stack(t_dclst *stack)
{
	t_dcnode	*current_node;
	t_dcnode	*next_node;

	if (!stack || !stack->begin)
		return ;
	current_node = stack->begin;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
		if (current_node == stack->begin)
			break ;
	}
	ft_bzero(stack, sizeof(t_dclst));
}
