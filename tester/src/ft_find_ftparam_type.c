/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ftparam_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:56:00 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:37:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

t_arg	*ft_find_ftparam_type(const char *name)
{
	int	i;
	int	name_len;

	i = 0;
	name_len = ft_strlen(name);
	while (g_func_map_int[i].name)
	{
		if (!ft_strncmp(name, g_func_map_int[i].name, name_len))
			return (g_func_map_int[i].arg_types);
		i++;
	}
	i = 0;
	while (g_func_map_size_t[i].name)
	{
		if (!ft_strncmp(name, g_func_map_size_t[i].name, name_len))
			return (g_func_map_size_t[i].arg_types);
		i++;
	}
	while (g_func_map_str[i].name)
	{
		if (!ft_strncmp(name, g_func_map_str[i].name, name_len))
			return (g_func_map_str[i].arg_types);
		i++;
	}
	return (NULL);
}
