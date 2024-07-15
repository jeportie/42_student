/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:44:28 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/15 16:55:05 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_wait_for_children(int num_commands)
{
	int	i;

	i = 0;
//	close(STDIN_FILENO);
	while (i < num_commands)
	{
		wait(NULL);
		i++;
	}
}

void	ft_fork_and_exec(t_pipex *pipex, char **envp)
{
	int	i;
	int	pid;

	i = 0;
	while (i < pipex->num_commands)
	{
		if (i < pipex->num_commands - 1)
		{
			pipe(pipex->pipefd);
			if (pipex->pipefd[0] == ERROR || pipex->pipefd[1] == ERROR)
			{
				gc_cleanup();
				exit(EXIT_FAILURE);
			}
		}
		pid = fork();
		ft_exec_pid(pipex, envp, pid, i);
		i++;
	}
	ft_wait_for_children(pipex->num_commands);
}
