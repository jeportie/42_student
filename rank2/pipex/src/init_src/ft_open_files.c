/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:00:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/08 01:38:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_open_files(t_pipex *pipex)
{
	int	fd;

	fd = open(pipex->input_file, O_RDONLY);
	ft_check_fd(fd, "Open input file error!\n");
	gc_fd_register(fd);
	pipex->commands[0].in_fd = fd;
	fd = open(pipex->output_file, O_WRONLY | O_CREAT | O_TRUNC, COPYMODE);
	ft_check_fd(fd, "Open output file error!\n");
	gc_fd_register(fd);
	pipex->commands[pipex->num_commands - 1].out_fd = fd;
}
