/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:24:17 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/18 09:45:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_split_parse(char *values_list, t_dclst *stack_a)
{
	long	value;
	int		len;
	char	**formatted_argv;

	formatted_argv = ft_split(values_list, ' ');
	if (!formatted_argv)
	{
		ft_putstr_fd("Error1\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	len = ft_argc_len(formatted_argv);
	if (!ft_validate_inputs(len, formatted_argv) || len < 3)
	{
		ft_free_split(formatted_argv);
		ft_putstr_fd("Error2\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	len--;
	while (len >= 0)
	{
		value = ft_atol(formatted_argv[len]);
		ft_push_to_stack(stack_a, value);
		len--;
	}
	ft_free_split(formatted_argv);
}

void	ft_args_parse(int argc, char **argv, t_dclst *stack_a)
{
	long	value;

	if (!ft_validate_inputs(argc, argv))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	argc--;
	while (argc > 0)
	{
		value = ft_atol(argv[argc]);
		ft_push_to_stack(stack_a, value);
		argc--;
	}
}

void	ft_parse_arg(int argc, char **argv, t_dclst *stack_a)
{
	if (argc == 2)
		ft_split_parse(argv[1], stack_a);
	else if (argc > 3)
		ft_args_parse(argc, argv, stack_a);
	else
	{
		ft_putstr_fd("Error3\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
