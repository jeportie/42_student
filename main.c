/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeromeP <JeromeP@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:21:56 by JeromeP           #+#    #+#             */
/*   Updated: 2023/11/12 17:02:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define MAX_TESTS 1000
#define MAX_TEST_LEN 2048

char **read_input_data(const char *file_path)
{
	int		fd;
	int		index;
	int		pos;
	char	ch;

	index = 0;
	pos = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (read(fd, &ch, 1) > 0 && index < MAX_TESTS)
	{

	}
}

int	ft_atoi_test(void)
{
	int	result;

	result = 0;

	return (0);
}

int	main(void)
{
	printf("Hello, welcome in the libft test programe.\n");

	{
		printf("Testing ft_atoi...\n");
		if (!ft_atoi_test())
		{
			printf("\n");	
		}
			printf("TEST : OK\n");
	}
	return (0);
}
