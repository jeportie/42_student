/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:12:33 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/18 09:47:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	ft_print_stack(t_dclst *stack, char name)
{
	t_dcnode	*current_node;

	ft_printf("\nstack_%c :\t", name);
	if (stack->begin == NULL)
	{
		ft_printf("NULL\n\n");
		return ;
	}
	current_node = stack->begin;
	while (current_node)
	{
		ft_printf("%i\t", current_node->value);
		current_node = current_node->next;
		if (current_node == stack->begin)
			break ;
	}
	ft_printf("\n\n");
}
