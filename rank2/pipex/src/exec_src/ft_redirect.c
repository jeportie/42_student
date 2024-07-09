/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:11:39 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/09 15:37:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_redirect_input(int in_fd)
{
	if (DEBUG_MODE == true)
		printf("Redirecting input FD: %d\n", in_fd);
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
	if (DEBUG_MODE == true)
		printf("Redirecting output FD: %d\n\n", out_fd);
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
	if (DEBUG_MODE == true)
		printf("\nRedirecting I/O for command: %s\n", command->cmd);
	if (command->in_fd != STDIN_FILENO)
		ft_redirect_input(command->in_fd);
	if (command->out_fd != STDOUT_FILENO)
		ft_redirect_output(command->out_fd);
}
