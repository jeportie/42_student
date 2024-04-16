/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/04/12 18:48:18 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/push_swap.h"
#include "include/ft_printf.h"

int	main(int argc, char **argv)
{
	t_dclst	*stack_a;
	t_dclst	*stack_b;

	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	if (argc > 1)
	{

		ft_parse_arg(argc, argv, stack_a);
		turkish_sort(stack_a, stack_b);
    	ft_print_stack(stack_a, 'a');
    	ft_print_stack(stack_b, 'b');
		ft_empty_stack(stack_a);
		ft_empty_stack(stack_b);
	}
	free(stack_a);
	free(stack_b);
	return (0);
}
