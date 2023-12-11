/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:58:25 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/10 18:04:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

void ft_strtoupper(char *str)
{
    if (!str) 
        return ;
    while (*str)
    {
        *str = ft_toupper((unsigned char)*str);
        str++;
    }
}
