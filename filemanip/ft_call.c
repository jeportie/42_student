/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:39:17 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/12 14:53:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

/*
 * FONCTION PERMETANT DE CHERCHER L'ADRESSE DE LA FONCTION CORESSPONDANT AU NOM
 * DONNEE EN ENTREE. VOIR LIBFMANIP_GLOBALS POUR CONSULTER LA TABLE DES 
 * FONCTIONS.
*/

func_int ft_call_func_int(const char *name, int lib)
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

func_str ft_call_func_str(const char *name, int lib)
{
	int	i;
	int	name_len;

	i = 0;
	name_len = ft_strlen(name) + 1;
	while (g_func_map_str[i].name)
	{
		if (!ft_strncmp(name, g_func_map_str[i].name, name_len))
		{
			if (lib == LIBC)
				return (g_func_map_str[i].libc_func);
			else
				return (g_func_map_str[i].ft_func);
		}
		i++;
	}
	return NULL;
}
