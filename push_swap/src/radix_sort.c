/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:00:46 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/23 21:14:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	radix_sort(t_dclst *stack_a, t_dclst *stack_b)
{
    ft_printf("\n");
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_printf("\n");
    ft_print_stack(stack_a, 'a');
    ft_print_stack(stack_b, 'b');
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_printf("\n");
    ss(stack_a, stack_b);
    rr(stack_a, stack_b);
    ft_printf("\n");
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_print_stack(stack_a, 'a');
    ft_print_stack(stack_b, 'b');
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_printf("\n");
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_printf("\n");
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    ft_print_stack(stack_a, 'a');
    ft_print_stack(stack_b, 'b');
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_printf("\n");
    ss(stack_a, stack_b);
    ft_printf("\n");
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_print_stack(stack_a, 'a');
    ft_print_stack(stack_b, 'b');
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    ft_printf("\n");
    rr(stack_a, stack_b);
    ft_printf("\n");
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_print_stack(stack_a, 'a');
    ft_print_stack(stack_b, 'b');
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_printf("\n");
    rrr(stack_a, stack_b);
    ft_printf("\n");
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_print_stack(stack_a, 'a');
    ft_print_stack(stack_b, 'b');
    ft_printf("\n");
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    ft_printf("\n");
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_print_stack(stack_a, 'a');
    ft_print_stack(stack_b, 'b');
}
