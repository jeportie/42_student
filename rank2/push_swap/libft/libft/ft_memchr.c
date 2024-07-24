/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:26:40 by neleon            #+#    #+#             */
/*   Updated: 2023/12/05 17:28:19 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem_s;

	mem_s = s;
	while (n-- > 0)
	{
		if (*mem_s == (unsigned char)c)
			return ((void *)mem_s);
		mem_s++;
	}
	return (NULL);
}
