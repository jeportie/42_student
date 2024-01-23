/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:46:51 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/23 16:41:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*test;

	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening test file:");
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < 5)
	{
		test = get_next_line(fd);
		if (test)
			printf("l%i: %s", i, test);
		i++;
	}
	return (0);
}
