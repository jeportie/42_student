/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:31:36 by neleon            #+#    #+#             */
/*   Updated: 2023/12/05 19:57:06 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			full_len;

	i = 0;
	if (!s)
		return (0);
	full_len = ft_strlen(s);
	if (start >= full_len)
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
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

// int	main(void)
// {
// 	char *str;
//     char *sub;
//     str = "Foo Bar Baz";
//     sub = ft_substr(str, 4, 3);
// 	printf("String : %s\n", str);
// 	printf("Substring : %s\n", sub);
//     free(sub);
// 	return (0);
// }
