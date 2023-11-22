/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:35:07 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/22 17:51:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	s_len;

//	if (!s)
//		return (NULL);
	s_len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!new_str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	new_str = ft_memcpy(new_str, s, s_len + 1);
	return (new_str);
}
