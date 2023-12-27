/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ftreturn_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:25:15 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/27 18:25:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

t_return	ft_find_ftreturn_type(const char *name)
{
	int	i;
	int	name_len;

	i = 0;
	name_len = ft_strlen(name);
	while (g_func_map_int[i].name)
	{
		if (!ft_strncmp(name, g_func_map_int[i].name, name_len))
			return (RETURN_INT);
		i++;
	}
	i = 0;
	while (g_func_map_size_t[i].name)
	{
		if (!ft_strncmp(name, g_func_map_size_t[i].name, name_len))
			return (RETURN_SIZE_T);
		i++;
	}
	i = 0;
	while (g_func_map_str[i].name)
	{
		if (!ft_strncmp(name, g_func_map_str[i].name, name_len))
			return (RETURN_STR);
		i++;
	}
	return (RETURN_VOID);
}
