/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:54:36 by neleon            #+#    #+#             */
/*   Updated: 2023/11/23 19:45:42 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	i;
// 	int	len;
// 	int	testChar[] = {'a', 'Z', -1, 128};

// 	i = 0;
// 	len = sizeof(testChar) / sizeof(testChar[0]);
// 	while (i < len)
// 	{
// 		if (ft_isascii(testChar[i]))
// 			printf("%c is part of the ascii table\n", testChar[i]);
// 		else
// 			printf("%c is not part of the ascii table\n", testChar[i]);
// 		i++;
// 	}
// 	return (0);
// }
