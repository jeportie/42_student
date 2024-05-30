/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argc_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:21:04 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 18:21:37 by jeportie         ###   ########.fr       */
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
