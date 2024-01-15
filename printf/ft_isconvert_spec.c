/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isconvert_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:39:09 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/15 20:01:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isconvert_spec(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}
