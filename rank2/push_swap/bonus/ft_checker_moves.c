/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:55:31 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/25 10:19:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_swap_move(t_stack **a, t_stack **b, char **line)
{
	if ((*line)[0] == 's' && (*line)[1] == 'a' && (*line)[2] == '\n')
		ft_swap_elements(a);
	else if ((*line)[0] == 's' && (*line)[1] == 'b' && (*line)[2] == '\n')
		ft_swap_elements(b);
	else if ((*line)[0] == 's' && (*line)[1] == 's' && (*line)[2] == '\n')
	{
		ft_swap_elements(a);
		ft_swap_elements(b);
	}
	else
		ft_error_checker(a, b, line);
}

static void	ft_push_move(t_stack **a, t_stack **b, char **line)
{
	if ((*line)[0] == 'p' && (*line)[1] == 'a' && (*line)[2] == '\n')
	{
		if (*b)
			ft_push_top_to_stack(b, a);
		else
			ft_error_checker(a, b, line);
	}
	else if ((*line)[0] == 'p' && (*line)[1] == 'b' && (*line)[2] == '\n')
	{
		if (*a)
			ft_push_top_to_stack(a, b);
		else
			ft_error_checker(a, b, line);
	}
	else
		ft_error_checker(a, b, line);
}

static void	ft_rotate_move(t_stack **a, t_stack **b, char **line)
{
	if ((*line)[0] == 'r' && (*line)[1] == 'a' && (*line)[2] == '\n')
		ft_rotate(a);
	else if ((*line)[0] == 'r' && (*line)[1] == 'b' && (*line)[2] == '\n')
		ft_rotate(b);
	else if ((*line)[0] == 'r' && (*line)[1] == 'r' && (*line)[2] == '\n')
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else
		ft_error_checker(a, b, line);
}

static void	ft_rev_rot_move(t_stack **a, t_stack **b, char **line)
{
	if ((*line)[0] == 'r' && (*line)[1] == 'r' && (*line)[2] == 'a'
		&& (*line)[3] == '\n')
		ft_rev_rotate(a);
	else if ((*line)[0] == 'r' && (*line)[1] == 'r' && (*line)[2] == 'b'
		&& (*line)[3] == '\n')
		ft_rev_rotate(b);
	else if ((*line)[0] == 'r' && (*line)[1] == 'r' && (*line)[2] == 'r'
		&& (*line)[3] == '\n')
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
	}
	else
		ft_error_checker(a, b, line);
}

void	ft_read_and_exec_move(t_stack **a, t_stack **b, char **line)
{
	if ((*line)[0] == 's')
		ft_swap_move(a, b, line);
	else if ((*line)[0] == 'p')
		ft_push_move(a, b, line);
	else if ((*line)[0] == 'r' && (*line)[1] == 'r' && (*line)[2] != '\n'
		&& (*line)[3] == '\n')
		ft_rev_rot_move(a, b, line);
	else if ((*line)[0] == 'r')
		ft_rotate_move(a, b, line);
	else
	{
		free(*line);
		line = NULL;
		ft_error_checker(a, b, line);
	}
}
