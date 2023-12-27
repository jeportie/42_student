/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:39:17 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/13 15:13:30 by jeportie         ###   ########.fr       */
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

/* 
 * Function to find the address of the function corresponding to the given name.
 * See 'libfmanip_globals' for the function table.
 */

func_size_t ft_call_func_size_t(const char *name, int lib)
{
    size_t  i;
    size_t  name_len;

    i = 0;
    name_len = ft_strlen(name) + 1; // Include null-terminator in comparison
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
    return NULL; // Return NULL if no matching function is found
}

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

