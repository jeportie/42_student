/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_func_size_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:12:51 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/27 18:13:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

/* 
 * Function to find the address of the function corresponding to the given name.
 * See 'libfmanip_globals' for the function table.
 */

func_size_t ft_call_func_size_t(const char *name, int lib)
{
    size_t  i;
    size_t  name_len;

    i = 0;
    name_len = ft_strlen(name) + 1;
    while (g_func_map_size_t[i].name)
    {
        if (!ft_strncmp(name, g_func_map_size_t[i].name, name_len))
        {
            if (lib == LIBC)
                return (g_func_map_size_t[i].libc_func);
            else
                return (g_func_map_size_t[i].ft_func);
        }
        i++;
    }
    return NULL;
}
