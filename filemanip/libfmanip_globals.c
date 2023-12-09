/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfmanip_globals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:15:27 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/09 15:16:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

t_funcmap_int_int g_func_map_int_int[] =
{
    {"isalpha", ft_isalpha, isalpha},
    {"isdigit", ft_isdigit, isdigit},
    {"toupper", ft_toupper, toupper},
    {"tolower", ft_tolower, tolower},
    {NULL, NULL, NULL}  // Marks the end of the array
};
