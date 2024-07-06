/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:00:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/06 13:00:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
#include <fcntl.h>

void	ft_check_fd(int fd, const char *error_message)
{
	if (fd == -1)
	{
		perror(error_message);
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
}

void	ft_open_files(t_pipex *pipex)
{
	int	fd;

	fd = open(pipex->input_file, O_RDONLY);
	ft_check_fd(fd, "Open input file error!\n");
	gc_fd_register(fd);
	pipex->commands[0].in_fd = fd;
	fd = open(pipex->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_check_fd(fd, "Open output file error!\n");
	gc_fd_register(fd);
	pipex->commands[pipex->num_commands - 1].out_fd = fd;
}
