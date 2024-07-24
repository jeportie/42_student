/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:54:14 by neleon            #+#    #+#             */
/*   Updated: 2023/11/23 19:46:10 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	char	testChar;

// 	if (ac == 2)
// 	{
// 		testChar = av[1][0];
// 		if (ft_isalpha(testChar))
// 			printf("%c is an alphabetical character\n", testChar);
// 		else
// 			printf("%c is not alphabetical character\n", testChar);
// 	}
// 	return (0);
// }
