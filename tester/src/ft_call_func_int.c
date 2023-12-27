/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_func_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:11:59 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/27 18:12:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

/* 
 * Function to find the address of the function corresponding to the given name.
 * See 'libfmanip_globals' for the function table.
 */

func_int ft_call_func_int(const char *name, int lib)
{
    int i;
    int name_len;

    i = 0;
    name_len = ft_strlen(name) + 1; // Include null-terminator in comparison
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
    return NULL; // Return NULL if no matching function is found
}
