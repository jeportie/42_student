/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:26 by neleon            #+#    #+#             */
/*   Updated: 2023/12/05 16:24:45 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	to_find;
	int		len;

	to_find = (char)c;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + len));
	while (*s)
	{
		if (*s == to_find)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
