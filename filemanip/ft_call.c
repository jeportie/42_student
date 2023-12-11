/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:39:17 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/10 13:00:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

func_int ft_call_ft(const char *name, int lib)
{
	int	i;
	int	name_len;

	i = 0;
	name_len = ft_strlen(name) + 1;
	while (g_func_map_int[i].name)
	{
		if (!ft_strncmp(name, g_func_map_int[i].name, name_len))
		{
			if (lib == LIBC)
				return (g_func_map_int[i].libc_func);
			else
				return (g_func_map_int[i].ft_func);
		}
		i++;
	}
	return NULL;
}
