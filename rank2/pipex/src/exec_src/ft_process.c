/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:20:09 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/11 15:03:04 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_update_prev_fd(t_pipex *pipex, int i)
{
	if (i < pipex->num_commands - 1)
	{
		pipex->prev_pipefd[0] = pipex->pipefd[0];
		pipex->prev_pipefd[1] = pipex->pipefd[1];
		ft_printf_fd(g_log_fd,
			"Parent: Updating prev_pipefd to [%d, %d]\n",
			pipex->prev_pipefd[0], pipex->prev_pipefd[1]);
	}
	else
	{
		pipex->prev_pipefd[0] = pipex->pipefd[0];
		pipex->prev_pipefd[1] = -1;
		ft_printf_fd(g_log_fd,
			"Parent: Updating prev_pipefd to [%d, %d]\n",
			pipex->prev_pipefd[0], pipex->prev_pipefd[1]);
	}
}

static void	ft_parent_process(t_pipex *pipex, int i)
{
	if (i < pipex->num_commands - 1)
	{
		ft_printf_fd(g_log_fd, "Parent: Closing write end of pipe (FD: %d)\n",
			pipex->pipefd[1]);
		close(pipex->pipefd[1]);
	}
	if (i > 0)
	{
		ft_printf_fd(g_log_fd,
			"Parent: Closing read end of previous pipe (FD: %d)\n",
			pipex->prev_pipefd[0]);
		close(pipex->prev_pipefd[0]);
	}
	ft_update_prev_fd(pipex, i);
}

static void	ft_child_io(t_pipex *pipex, int i)
{
	if (i == 0)
	{
		pipex->commands[i].out_fd = pipex->pipefd[1];
		ft_printf_fd(g_log_fd,
			"Child: First command, setting FDout to pipe write end (FD: %d)\n",
			pipex->pipefd[1]);
	}
	else if (i == pipex->num_commands - 1)
	{
		pipex->commands[i].in_fd = pipex->prev_pipefd[0];
		ft_printf_fd(g_log_fd,
			"Child: Last cmd, setting FDin to prev pipe read end (FD: %d)\n",
			pipex->prev_pipefd[0]);
	}
	else
	{
		pipex->commands[i].in_fd = pipex->prev_pipefd[0];
		pipex->commands[i].out_fd = pipex->pipefd[1];
		ft_printf_fd(g_log_fd,
			"Child: Middle cmd, set FDin to prev pipe read end (FD: %d)",
			pipex->prev_pipefd[0], pipex->pipefd[1]);
		ft_printf_fd(g_log_fd,
			" and FDout to pipe write end (FD: %d)\n", pipex->prev_pipefd[0],
			pipex->pipefd[1]);
	}
}

static void	ft_child_process(t_command *command, char **envp)
{
	ft_printf_fd(g_log_fd,
		"\e[34mChild process executing command: %s\e[0m\n", command->cmd);
	ft_redirect_io(command);
	execve(command->cmd, command->args, envp);
	perror("Execve Error !\n");
	gc_cleanup();
	exit(EXIT_FAILURE);
}

void	ft_exec_pid(t_pipex *pipex, char **envp, int pid, int i)
{
	if (pid == ERROR)
		ft_check_pid(pid);
	else if (pid == CHILD)
	{
		ft_printf_fd(g_log_fd,
			"\e[34mChild process (PID: %d) for command: %s\e[0m\n",
			pid, pipex->commands[i].cmd);
		ft_child_io(pipex, i);
		ft_child_process(&pipex->commands[i], envp);
		gc_collect();
	}
	else
	{
		ft_printf_fd(g_log_fd,
			"\e[32mParent process handling child (PID : %d) for cmd: %s\e[0m\n",
			pid, pipex->commands[i].cmd);
		ft_parent_process(pipex, i);
		gc_collect();
	}
}
