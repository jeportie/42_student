/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeromeP <JeromeP@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:21:56 by JeromeP           #+#    #+#             */
/*   Updated: 2023/11/11 14:23:02 by JeromeP          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int	result;

	if (argc != 2)
		return (1);
	result = ft_atoi(argv[1]);
	printf("ft_atoi result :%d\n", result);
	result = atoi(argv[1]);
	printf("atoi result : %d\n", result);
	return (0);
}
