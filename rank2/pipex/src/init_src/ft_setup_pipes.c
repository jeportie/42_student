/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:43:32 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/06 12:43:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_setup_pipes(t_pipex *pipex)
{
	if (pipe(pipex->pipefd) == -1)
	{
		perror("Pipe Error");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	gc_fd_register(pipex->pipefd[0]);
	gc_fd_register(pipex->pipefd[1]);
}
