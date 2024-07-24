/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:44:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 14:33:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_duplicate_in_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->nb == runner->nb)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	ft_is_valid_number_string(char *str)
{
	int	i;

	i = 0;
	if (!(ft_isdigit(str[i]) || str[i] != '-' || str[i] != '+'))
		return (0);
	if ((str[0] == '-' || str[0] == '+') && !ft_isdigit(str[1]))
		return (0);
	if (str[0] && (str[0] == '+' || str[0] == '-'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		if (str[i] == '-' && str[i - 1] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_not_int(t_stack *stack)
{
	while (stack)
	{
		if (stack->nb > INT_MAX || stack->nb < INT_MIN)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_print_error(t_stack **stack)
{
	ft_free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
