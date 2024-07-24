/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:48:22 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 15:50:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*joined_args;

	a = NULL;
	b = ft_init_b();
	joined_args = NULL;
	if (ac > 1)
	{
		ft_check_empty_args(ac, av);
		joined_args = ft_join_arguments(ac, av);
		ft_validate_and_init_stack(&a, joined_args);
		free(joined_args);
		ft_check_dup_and_sort(&a, &b);
		ft_free_stack(&a);
		ft_free_stack(&b);
	}
	return (0);
}
