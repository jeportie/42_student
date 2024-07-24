/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:10:24 by neleon            #+#    #+#             */
/*   Updated: 2023/12/05 16:25:55 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	to_find;

	to_find = (char)c;
	len = ft_strlen(s);
	if (to_find == '\0')
		return ((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == to_find)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
