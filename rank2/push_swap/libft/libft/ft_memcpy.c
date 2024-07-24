/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:54:59 by neleon            #+#    #+#             */
/*   Updated: 2023/12/05 19:24:29 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	dst[20];
// 	char	src[100] = "Hello it's me";

// 	ft_memcpy(dst, src, 7);
// 	printf("%s\n", dst);
// 	return (0);
// }
