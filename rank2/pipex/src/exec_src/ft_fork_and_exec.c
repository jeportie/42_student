/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:44:28 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/11 13:27:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_wait_for_children(int num_commands)
{
	int	i;

	if (DEBUG_MODE == true)
		ft_printf_fd(g_log_fd, "\nWaiting for %d children\n", num_commands);
	i = 0;
	while (i < num_commands)
	{
		if (DEBUG_MODE == true)
			ft_printf_fd(g_log_fd, "Waiting for child %d\n", i + 1);
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
			ft_printf_fd(g_log_fd, "Forking for command %d: %s\n",
				i + 1, pipex->commands[i].cmd);
		if (i < pipex->num_commands - 1)
		{
			if (pipe(pipex->pipefd) == -1)
			{
				gc_cleanup();
				exit(EXIT_FAILURE);
			}
			if (DEBUG_MODE == true)
				ft_printf_fd(g_log_fd, "Created pipe FDs: [%d, %d]\n",
					pipex->pipefd[0], pipex->pipefd[1]);
		}
		pid = fork();
		ft_exec_pid(pipex, envp, pid, i);
		i++;
	}
	ft_wait_for_children(pipex->num_commands);
}
