/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:14:13 by neleon            #+#    #+#             */
/*   Updated: 2024/05/29 00:24:51 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			full_len;

	i = 0;
	if (!s)
		return (NULL);
	full_len = gnl_strlen(s);
	if (start >= full_len)
		return (NULL);
	if (start + len > full_len)
		len = full_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start] && len-- > 0)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	*gnl_strchr(char *s, int c)
{
	char	to_find;
	int		len;

	if (!s)
		return (NULL);
	to_find = (char)c;
	len = gnl_strlen(s);
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

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	len_s1 = gnl_strlen(s1);
	len_s2 = gnl_strlen(s2);
	join = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		join[i] = s1[i];
	j = -1;
	while (++j < len_s2)
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return (join);
}

char	*gnl_strdup(char *s1)
{
	size_t	len;
	char	*str;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	len = gnl_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
