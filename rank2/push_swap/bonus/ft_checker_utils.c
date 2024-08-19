/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:55:47 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/25 08:45:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_prep_main(int ac, char **av, t_stack **a, t_stack **b)
{
	char	*joined_args;

	joined_args = NULL;
	ft_check_empty_args(ac, av);
	joined_args = ft_join_arguments(ac, av);
	ft_validate_and_init_stack(a, joined_args);
	free(joined_args);
	if (ft_check_duplicate_in_stack(*a) || ft_is_not_int(*a))
		ft_error_checker(a, b, NULL);
}

void	ft_error_checker(t_stack **a, t_stack **b, char **line)
{
	ft_free_stack(a);
	ft_free_stack(b);
	get_next_line(0);
	ft_putstr_fd("Error\n", 2);
	if (!line)
		exit(1);
	free(*line);
	*line = NULL;
	exit(1);
}
