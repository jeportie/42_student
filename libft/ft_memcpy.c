/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:36:02 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/22 17:39:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*mem_dest;
	const unsigned char	*mem_src;

	if (dest == NULL && src == NULL)
    	return NULL;
	mem_dest = dest;
	mem_src = src;
	while (n--)
		*mem_dest++ = *mem_src++;
	return (dest);
}
