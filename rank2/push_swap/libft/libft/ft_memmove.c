/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:55:07 by neleon            #+#    #+#             */
/*   Updated: 2023/12/05 19:38:01 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	if (d < s)
		while (n-- > 0)
			*d++ = *s++;
	else
		while (n-- > 0)
			*(d + n) = *(s + n);
	return (dest);
}

// int	main(void)
// {
// 	char	dst[20];
// 	char	src[100] = "Hello it's me";

// 	ft_memmove(dst, src, 7);
// 	printf("%s\n", dst);
// 	return (0);
// }
