/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:54:51 by neleon            #+#    #+#             */
/*   Updated: 2023/11/23 19:46:37 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	i;
// 	int	len;
// 	int	testChar[] = {'a', 'Z', 7, 127};

// 	i = 0;
// 	len = sizeof(testChar) / sizeof(testChar[0]);
// 	while (i < len)
// 	{
// 		if (ft_isprint(testChar[i]))
// 			printf("%c (code %d) is printable\n", testChar[i], testChar[i]);
// 		else
// 			printf("%c (code %d) is not printable\n", testChar[i], testChar[i]);
// 		i++;
// 	}
// 	return (0);
// }
