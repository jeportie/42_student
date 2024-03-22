/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:24:17 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 15:37:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_argc_len(char **argv)
{
	int	len;

	len = 0;
	if (!argv)
		return (0);
	while (*argv)
	{
		len++;
		argv++;
	}
	return (len);
}

bool	ft_validate_inputs(int argc, char **argv)
{
	return (0);
}

void	ft_free_split(char **formatted_argv)
{
	char	**tmp;

	tmp = formatted_argv;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(formatted_argv);
}

void	ft_push_to_stack(t_dclst *stack, long value)
{

}

void	ft_split_parse(char *values_list, t_dclst *stack_a)
{
	long	value;
	int		len;
	char	**formatted_argv;

	formatted_argv = ft_split(values_list, ' ');
	if (!formatted_argv)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	len = ft_argc_len(formatted_argv);
	if (!ft_validate_inputs(len, formatted_argv))
	{
		ft_free_split(formatted_argv);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	len--;
	while (len > 1)
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
	while (argc > 1)
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
	if (argc > 3)
		ft_args_parse(argc, argv, stack_a);
	else
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

/*
 * 3 parsing format :
 * One value per argument:
 * 		-ft_valid_input
 * 		-ft_is_integer
 * 		-ft_addto_stack with the help of ft_atol
 * All the value in one string argument:
 * 		-make a function to detect separators
 * 		-ft_split
 * 		- one value per arg process
 * The filepath of a file with all values on it:
 * 		-
 */
