/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:00:46 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 17:35:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	radix_sort(t_dclst *stack_a, t_dclst *stack_b)
{
    t_dcnode *current_node;

    ft_printf("stack_a :\t");
	if (stack_a->begin == NULL)
	{
        ft_printf("NULL\n");
        return;
    }
    current_node = stack_a->begin;
    while (current_node)
    {
        ft_printf("%i\t", current_node->value);
        current_node = current_node->next;
        if (current_node == stack_a->begin)
            break;
    }
    ft_printf("\n\n");
    ft_printf("stack_b : ");
	if (stack_b->begin == NULL)
	{
        ft_printf("NULL\n");
    }
    current_node = stack_b->begin;
    while (current_node)
    {
        ft_printf("%i\t", current_node->value);
        current_node = current_node->next;
        if (current_node == stack_b->begin)
            break;
    }

    ft_printf("\n");
    sa(stack_a);
    ft_printf("\n");

    ft_printf("stack_a :\t");
	if (stack_a->begin == NULL)
	{
        ft_printf("NULL\n");
        return;
    }
    current_node = stack_a->begin;
    while (current_node)
    {
        ft_printf("%i\t", current_node->value);
        current_node = current_node->next;
        if (current_node == stack_a->begin)
            break;
    }
    ft_printf("\n\n");
    ft_printf("stack_b : ");
	if (stack_b->begin == NULL)
	{
        ft_printf("NULL\n");
    }
    current_node = stack_b->begin;
    while (current_node)
    {
        ft_printf("%i\t", current_node->value);
        current_node = current_node->next;
        if (current_node == stack_b->begin)
            break;
    }
    ft_printf("\n");
}
