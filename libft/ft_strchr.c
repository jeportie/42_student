/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:33:53 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/15 19:17:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(const char *s, int c)
{
	char	first_occurrence;

	first_occurrence = (char)c;
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
