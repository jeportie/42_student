/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_func_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:14:03 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/27 18:14:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

/* 
 * Similar to 'ft_call_func_int' but for string-returning functions.
 */

func_str ft_call_func_str(const char *name, int lib)
{
    int i;
    int name_len;

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
