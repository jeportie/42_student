/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:58:15 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/22 20:01:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*mem_dest;
	unsigned char	*mem_src;

	if (!dest && !src)
		return (NULL);
	mem_dest = (unsigned char *)dest;
	mem_src = (unsigned char *)src;
	while (n-- && mem_dest && mem_src)
		*mem_dest++ = *mem_src++;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len1;
	size_t	len2;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2;
	joined_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!joined_str)
		return (NULL);
	ft_memcpy(joined_str, s1, len1);
	ft_memcpy(joined_str + len1, s2, len2);
	joined_str[total_len] = '\0';
	return (joined_str);
}

char	*ft_strchr(const char *s, int c)
{
	char	first_occurrence;

	first_occurrence = (unsigned char)c;
	while (*s)
	{
		if (*s == first_occurrence)
			return ((char *)s);
		s++;
	}
	if (first_occurrence == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	s_len;

	s_len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!new_str)
		return (NULL);
	new_str = ft_memcpy(new_str, s, s_len + 1);
	return (new_str);
}
