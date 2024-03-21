/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:21:03 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/21 14:33:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*test;

	fd = open("tests/testfile.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening test file:");
		exit(EXIT_FAILURE);
	}
	i = 1;
	test = get_next_line(fd);
	while (test != NULL)
	{
		ft_printf("l%i: %s", i, test);
		free(test);
		i++;
		test = get_next_line(fd);
	}
	close(fd);
	return (0);
}
