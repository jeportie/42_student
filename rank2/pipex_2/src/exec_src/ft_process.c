/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:20:09 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/15 21:14:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_parent_process(t_pipex *pipex, int i)
{
	if (i < pipex->num_commands - 1)
		close(pipex->pipefd[1]);
	if (i > 0)
		close(pipex->pipefd[0]);
}

static void	ft_child_process(t_pipex *pipex, int i, char **envp)
{
	if (i == 0)
	{
		close(pipex->pipefd[0]);
		pipex->commands[i].in_fd = open(pipex->input_file, O_RDONLY);
		ft_check_fd(pipex->commands[i].in_fd, "Open input file error!\n");
		gc_fd_register(pipex->commands[i].in_fd);
		ft_redirect_input(pipex->commands[i].in_fd);
		ft_redirect_output(pipex->pipefd[1]);
	}
	else if (i == pipex->num_commands - 1)
	{
		close(pipex->pipefd[1]);
		pipex->commands[i].out_fd
			= open(pipex->output_file, O_WRONLY | O_CREAT | O_TRUNC, COPYMODE);
		ft_check_fd(pipex->commands[i].out_fd, "Open output file error!\n");
		gc_fd_register(pipex->commands[i].out_fd);
		ft_redirect_input(pipex->pipefd[0]);
		ft_redirect_output(pipex->commands[i].out_fd);
	}
	else
	{
		pipex->commands[i].in_fd = pipex->pipefd[0];
		pipex->commands[i].out_fd = pipex->pipefd[1];
	}
	execve(pipex->commands[i].cmd, pipex->commands[i].args, envp);
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
		ft_child_process(pipex, i, envp);
		gc_collect();
	}
	else
	{
		ft_parent_process(pipex, i);
		gc_collect();
	}
}
