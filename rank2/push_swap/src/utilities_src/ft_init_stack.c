/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:00:44 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/21 15:38:18 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init_stack(t_dclst **stack)
{
	if (!stack)
		return ;
	*stack = (t_dclst *)malloc(sizeof(t_dclst));
	if (!*stack)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_bzero(*stack, sizeof(t_dclst));
}
