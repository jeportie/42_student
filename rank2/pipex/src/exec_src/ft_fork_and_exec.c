/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:44:28 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/07 16:53:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_redirect_io(t_command *command)
{
	if (command->in_fd != STDIN_FILENO)
		ft_redirect_input(command->in_fd);
	if (command->out_fd != STDOUT_FILENO)
		ft_redirect_output(command->out_fd);
}

void	ft_redirect_input(int in_fd)
{
	if (dup2(in_fd, STDIN_FILENO) == -1)
	{
		perror(" Dup2 Error ! (input)\n");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	close(in_fd);
}

void	ft_redirect_output(int out_fd)
{
	if (dup2(out_fd, STDOUT_FILENO) == -1)
	{
		perror(" Dup2 Error ! (output)\n");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	close(out_fd);
}

void	ft_child_process(t_command *command, char **envp)
{
//	ft_redirect_io(command);
	execve(command->cmd, command->args, envp);
	perror("Execve Error");
	gc_cleanup();
	exit(EXIT_FAILURE);
}

void	ft_parent_process(int pipefd[2])
{
	close(pipefd[1]);
}

static void	ft_check_pid(t_pipex *pipex, char **envp, int pid, int i)
{
	if (pid == -1)
	{
		perror("Forking Error !\n");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		ft_child_process(&pipex->commands[i], envp);
	else
		ft_parent_process(pipex->pipefd);
}

void	ft_close_pipes(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
}

void	ft_wait_for_children(int num_commands)
{
	int i;

	i = 0;
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
		pid = fork();
		ft_check_pid(pipex, envp, pid, i);
		i++;
	}
	ft_close_pipes(pipex);
	ft_wait_for_children(pipex->num_commands);
}
