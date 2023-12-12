/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfmanip_globals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:15:27 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/12 16:13:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

t_arg argt_str[] = {ARG_STRING};
t_arg argt_int[] = {ARG_INT};
t_arg argt_vvz[] = {ARG_CONST_VOID, ARG_CONST_VOID, ARG_SIZE_T};
t_arg argt_ssz[] = {ARG_CONST_STRING, ARG_CONST_STRING, ARG_SIZE_T};
t_arg argt_si[] = {ARG_CONST_STRING, ARG_INT};

t_funcmap_int g_func_map_int[] =
{
    {"atoi", ft_atoi, atoi, argt_str},
    {"isalnum", ft_isalnum, isalnum, argt_int},
    {"isalpha", ft_isalpha, isalpha, argt_int},
    {"isascii", ft_isascii, isascii, argt_int},
    {"isdigit", ft_isdigit, isdigit, argt_int},
    {"isprint", ft_isprint, isprint, argt_int},
    {"memcmp", ft_memcmp, memcmp, argt_vvz},
    {"strncmp", ft_strncmp, strncmp, argt_ssz},
    {"toupper", ft_toupper, toupper, argt_int},
    {"tolower", ft_tolower, tolower, argt_int},
    {NULL, NULL, NULL, NULL}  // Marks the end of the array
};

t_funcmap_str g_func_map_str[] =
{
    {"strchr", ft_strchr, strchr, argt_si},
    {"strdup", ft_strdup, strdup, argt_str},
    {"strnstr", ft_strnstr, strnstr, argt_ssz},
    {"strrchr", ft_strrchr, strrchr, argt_si},
    {NULL, NULL, NULL, NULL}  // Marks the end of the array
};
