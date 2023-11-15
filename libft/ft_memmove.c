/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:36:10 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/15 01:02:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*memloc_dest;
	unsigned char		*memloc_end_dest;
	const unsigned char	*memloc_src;
	const unsigned char	*memloc_end_src;

	memloc_dest = (unsigned char *)dest;
	memloc_src = (const unsigned char *)src;
	memloc_end_dest = memloc_dest + (n - 1);
	memloc_end_src = memloc_src + (n - 1);
	if (memloc_dest < memloc_src)
		ft_memcpy(dest, src, n);
	else
		while (n--)
			*memloc_end_dest++ = *memloc_end_src++;
	return (dest);
}
