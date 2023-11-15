/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:36:02 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/15 01:01:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*mem_dest;
	const unsigned char	*mem_src;

	mem_dest = dest;
	mem_src = src;
	while (n--)
		*mem_dest++ = *mem_src++;
	return (dest);
}
