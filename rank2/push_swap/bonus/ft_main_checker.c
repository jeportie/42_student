/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:56:04 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 14:32:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = ft_init_b();
	line = NULL;
	if (ac > 1)
	{	
		ft_prep_main(ac, av, &a, &b);
		line = get_next_line(0);
		if (!line && ft_is_sorted(a))
			ft_putstr_fd("OK\n", 1);
		else if (!line && !ft_is_sorted(a))
			ft_putstr_fd("KO\n", 1);
		else
			ft_checker(&a, &b, &line);
		get_next_line(0);
		ft_free_stack(&a);
		ft_free_stack(&b);
		if (line)
			free(line);
	}
	return (0);
}
