/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_and_exec_cft.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:06:54 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/09 15:07:42 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

int	ft_call_and_exec_cft(const char *name, int arg, int lib)
{
	int	i;
	int	name_len;

	i = 0;
	name_len = ft_strlen(name) + 1;
	while (g_func_map_int_int[i].name)
	{
		if (!ft_strncmp(name, g_func_map_int_int[i].name, name_len))
		{
			if (lib == LIBC)
				return (g_func_map_int_int[i].libc_func(arg));
			else
				return (g_func_map_int_int[i].ft_func(arg));
		}
		i++;
	}
	printf("Function not found: %s\n", name);
	return (-1);
}
