/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:24:17 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 17:21:35 by jeportie         ###   ########.fr       */
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

bool	ft_isinteger(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return false;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	ft_validate_inputs(int argc, char **argv)
{
	int		i;
	int		j;
	long	value_i;
	long	value_j;

	i = 1;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i]))
			return (false);
		value_i = ft_atol(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			value_j = ft_atol(argv[j]);
			if (value_i == value_j)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
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
	t_dcnode	*new_node;

	new_node = (t_dcnode *)malloc(sizeof(t_dcnode));
	if (!new_node)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	new_node->value = value;
	if (!stack->begin)
	{
		stack->begin = new_node;
		stack->end = new_node;
		new_node->next = NULL;
		new_node->back = NULL;
	}
	else
	{
		new_node->next = stack->begin;
		stack->begin->back = new_node;
		new_node->back = NULL;
		stack->begin = new_node;
	}
	stack->length += 1;
}

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
	if (!ft_validate_inputs(len, formatted_argv))
	{
		ft_free_split(formatted_argv);
		ft_putstr_fd("Error2\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	len--;
	while (len > 0)
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
