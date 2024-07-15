/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:11:39 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/15 16:50:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_redirect_input(int in_fd)
{
	if (dup2(in_fd, STDIN_FILENO) == -1)
	{
		perror(" Dup2 Error ! (input)\n");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	close(in_fd);
}

static void	ft_redirect_output(int out_fd)
{
	if (dup2(out_fd, STDOUT_FILENO) == -1)
	{
		perror(" Dup2 Error ! (output)\n");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	close(out_fd);
}

void	ft_redirect_io(t_command *command)
{
	if (command->in_fd != STDIN_FILENO)
		ft_redirect_input(command->in_fd);
	if (command->out_fd != STDOUT_FILENO)
		ft_redirect_output(command->out_fd);
}
