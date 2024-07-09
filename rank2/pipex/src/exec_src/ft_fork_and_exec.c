/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:44:28 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/09 15:26:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_close_pipes(t_pipex *pipex)
{
	if (DEBUG_MODE == true)
		ft_printf("Closing pipe FDs: [%d, %d]\n", pipex->pipefd[0],
			pipex->pipefd[1]);
	if (pipex->pipefd[0] != -1)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] != -1)
		close(pipex->pipefd[1]);
}

static void	ft_wait_for_children(int num_commands)
{
	int	i;

	if (DEBUG_MODE == true)
		ft_printf("\nWaiting for %d children\n", num_commands);
	i = 0;
	while (i < num_commands)
	{
		if (DEBUG_MODE == true)
			ft_printf("Waiting for child %d\n", i + 1);
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
		if (DEBUG_MODE == true)
			ft_printf("Forking for command %d: %s\n",
				i + 1, pipex->commands[i].cmd);
		if (i < pipex->num_commands - 1)
		{
			if (pipe(pipex->pipefd) == -1)
			{
				gc_cleanup();
				exit(EXIT_FAILURE);
			}
			if (DEBUG_MODE == true)
				ft_printf("Created pipe FDs: [%d, %d]\n",
					pipex->pipefd[0], pipex->pipefd[1]);
		}
		pid = fork();
		ft_exec_pid(pipex, envp, pid, i);
		i++;
	}
	ft_wait_for_children(pipex->num_commands);
}
