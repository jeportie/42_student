/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:20:09 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/09 15:33:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_child_process(t_command *command, char **envp)
{
	if (DEBUG_MODE == true)
		ft_printf("Executing Command: %s\n", command->cmd);
	ft_redirect_io(command);
	execve(command->cmd, command->args, envp);
	perror("Execve Error");
	gc_cleanup();
	exit(EXIT_FAILURE);
}

static void	ft_parent_process(t_pipex *pipex, int pid, int i)
{
	if (i < pipex->num_commands - 1)
	{
		close(pipex->pipefd[1]);
		pipex->pipefd[1] = -1;
	}
	if (i > 0)
	{
		close(pipex->prev_pipefd[0]);
		pipex->prev_pipefd[0] = -1;
	}
	if (i < pipex->num_commands - 1)
	{
		pipex->prev_pipefd[0] = pipex->pipefd[0];
		pipex->prev_pipefd[1] = pipex->pipefd[1];
	}
	else
	{
		pipex->prev_pipefd[0] = pipex->pipefd[0];
		pipex->prev_pipefd[1] = -1;
	}
}

static void	ft_child_io(t_pipex *pipex, int i)
{
	if (i == 0)
	{
		pipex->commands[i].in_fd = open(pipex->input_file, O_RDONLY);
		ft_check_fd(pipex->commands[i].in_fd, "Open Input File Error !\n");
		pipex->commands[i].out_fd = pipex->pipefd[1];
	}
	else if (i == pipex->num_commands - 1)
	{
		pipex->commands[i].in_fd = pipex->prev_pipefd[0];
		pipex->commands[i].out_fd = open(pipex->output_file,
				O_WRONLY | O_CREAT | O_TRUNC, COPYMODE);
		ft_check_fd(pipex->commands[i].out_fd, "Open Output file Error !\n");
	}
	else
	{
		pipex->commands[i].in_fd = pipex->prev_pipefd[0];
		pipex->commands[i].out_fd = pipex->pipefd[1];
	}
}

void	ft_exec_pid(t_pipex *pipex, char **envp, int pid, int i)
{
	if (pid == ERROR)
		ft_check_pid(pid);
	else if (pid == CHILD)
	{
		ft_child_io(pipex, i);
		ft_child_process(&pipex->commands[i], envp);
	}
	else
		ft_parent_process(pipex, pid, i);
}
