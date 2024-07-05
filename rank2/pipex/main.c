/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/06 00:15:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_redirect_inputs(const char *file, const char *cmd)
{
	int		fd;
	pid_t	pid;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Open Error!\n");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	gc_fd_register(fd);
	pid = fork();
	if (pid == -1)
	{
		perror("Fork Error!\n");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			perror("Dup2 Error !\n");
			gc_cleanup();
			exit(EXIT_FAILURE);
		}
		execlp(cmd, cmd, (char *) NULL);
		perror("Execlp Error!\n");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}

int	main(void)
{
	int argc;

	argc = 3;
	if (argc != 3)
	{
		ft_putstr_fd("Usage : ./pipex <file1><cmd>\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_redirect_inputs("test.txt", "cat");
	gc_cleanup();
	return (EXIT_SUCCESS);
}
