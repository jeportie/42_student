/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ftparam_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:56:00 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/10 18:30:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

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
	return (NULL);
}
