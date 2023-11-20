/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeromeP <JeromeP@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:54:13 by JeromeP           #+#    #+#             */
/*   Updated: 2023/11/17 21:11:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ischarset(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	ft_substr_len(char *str, char *charset)
{
	int len;

	while(*str && !ft_ischarset(*str, charset))
		len++;
	return (len);
}

int	ft_count_words(char *str, char *charset)
{
	int words;

	words = 0;
	while (*str)
	{
		while (*str && ft_ischarset(*str, charset))
				str++;
		if (*str && !ft_ischarset(*str, charset))
		{
			words++;
			while (*str && !ft_ischarset(*str, charset))
				str++;
		}
	}
	return (words);
}

char *ft_strnpcy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (*src && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char **ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		words;
	int		len;

	words = ft_count_words(str, charset);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str && ft_ischarset(*str, charset))
			str++;
		len = ft_substr_len(str, charset);
		tab[i] = malloc(sizeof(char) * (len + 1));
		if (!tab[i])
			return (NULL);
		ft_strnpcy(tab[i], str, len);
		str += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
