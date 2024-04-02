/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sub_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:33:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/02 20:08:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

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
		current->above_median = (position <= median_position);
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
