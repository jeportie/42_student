/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:44:28 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/08 18:58:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_redirect_input(int in_fd)
{
	if (DEBUG_MODE == true)
		ft_printf("Redirecting input FD: %d\n", in_fd);
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
	if (DEBUG_MODE == true)
		ft_printf("Redirecting output FD: %d\n\n", out_fd);
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
		ft_printf("Redirecting I/O for command: %s\n", command->cmd);
	if (command->in_fd != STDIN_FILENO)
		ft_redirect_input(command->in_fd);
	if (command->out_fd != STDOUT_FILENO)
		ft_redirect_output(command->out_fd);
}

void	ft_child_process(t_command *command, char **envp)
{
	if (DEBUG_MODE == true)
		ft_printf("Executing Command: %s\n", command->cmd);
	ft_redirect_io(command);
	execve(command->cmd, command->args, envp);
	perror("Execve Error");
	gc_cleanup();
	exit(EXIT_FAILURE);
}

void	ft_parent_process(t_pipex *pipex)
{
	if (DEBUG_MODE == true)
		ft_printf("Parent process closing pipe FDs: [%d, %d]\n",
			pipex->pipefd[0], pipex->pipefd[1]);
	ft_close_pipes(pipex);
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
	{
		if (DEBUG_MODE == true)
			ft_printf("In child process %d for command: %s\n", getpid(), pipex->commands[i].cmd);
		
		if (i == 0) // First command
		{
			pipex->commands[i].in_fd = open(pipex->input_file, O_RDONLY);
			ft_check_fd(pipex->commands[i].in_fd, "Open Input File Error !\n");
			if (pipex->num_commands > 1)
				pipex->commands[i].out_fd = pipex->pipefd[1];
		}
		else if (i == pipex->num_commands - 1) // Last command
		{
			pipex->commands[i].out_fd = open(pipex->output_file, O_WRONLY | O_CREAT | O_TRUNC, COPYMODE);
			ft_check_fd(pipex->commands[i].out_fd, "Open Output file Error !\n");
			pipex->commands[i].in_fd = pipex->pipefd[0];
		}
		else // Middle command
		{
			pipex->commands[i].in_fd = pipex->pipefd[0];
			pipex->commands[i].out_fd = pipex->pipefd[1];
		}
		ft_child_process(&pipex->commands[i], envp);
	}
	else
	{
		if (DEBUG_MODE == true)
			ft_printf("Forked process with PID: %d for command: %s\n", pid, pipex->commands[i].cmd);
		if (i < pipex->num_commands - 1)
		{
			close(pipex->pipefd[1]); // Close write end of the pipe in the parent process
			pipex->pipefd[1] = -1;
		}
		if (i > 0)
		{
			close(pipex->pipefd[0]); // Close read end of the pipe in the parent process
			pipex->pipefd[0] = -1;
		}
	}
}

void	ft_close_pipes(t_pipex *pipex)
{
	if (pipex->pipefd[0] != -1)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] != -1)
		close(pipex->pipefd[1]);
}

void	ft_wait_for_children(int num_commands)
{
	int i;

	if (DEBUG_MODE == true)
		ft_printf("\nWaiting for %d children\n", num_commands);
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
		if (DEBUG_MODE == true)
			ft_printf("Forking for command %d: %s\n", i + 1, pipex->commands[i].cmd);
		if (i < pipex->num_commands - 1)
		{
			if (pipe(pipex->pipefd) == -1)
			{
				perror("Pipe Error !\n");
				gc_cleanup();
				exit(EXIT_FAILURE);
			}
			ft_printf("Created pipe FDs: [%d, %d]\n", pipex->pipefd[0], pipex->pipefd[1]);
		}
		pid = fork();
		ft_check_pid(pipex, envp, pid, i);
		i++;
	}
	ft_wait_for_children(pipex->num_commands);
	ft_close_pipes(pipex); // Close any remaining pipes
}

/*
#include "../../include/pipex.h"


void	ft_redirect_input(int in_fd)
{
	if (DEBUG_MODE == true)
		ft_printf("Redirecting input FD: %d\n", in_fd);
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
	if (DEBUG_MODE == true)
			ft_printf("Redirecting output FD: %d\n\n", out_fd);
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
		ft_printf("Redirecting I/O for command: %s\n", command->cmd);
	if (command->in_fd != STDIN_FILENO && command->in_fd != -1)
		ft_redirect_input(command->in_fd);
	if (command->out_fd != STDOUT_FILENO && command->out_fd != -1)
		ft_redirect_output(command->out_fd);
}

void	ft_child_process(t_command *command, char **envp)
{
	if (DEBUG_MODE == true)
			ft_printf("Executing Command: %s\n", command->cmd);
	ft_redirect_io(command);
	execve(command->cmd, command->args, envp);
	perror("Execve Error");
	gc_cleanup();
	exit(EXIT_FAILURE);
}

void	ft_parent_process(t_pipex *pipex)
{
	if (DEBUG_MODE == true)
			ft_printf("Parent process closing pipe FDs: [%d, %d]\n",
					pipex->pipefd[0], pipex->pipefd[1]);
	close(pipex->pipefd[1]);
	if (pipex->pipefd[1] != -1)
	{
		close(pipex->pipefd[1]);
		pipex->pipefd[1] = -1;
	}
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
	{
		if (DEBUG_MODE == true)
           	ft_printf("In child process %d for command: %s\n",
					getpid(), pipex->commands[i].cmd);
		if (i == 0)
		{
			pipex->commands[i].in_fd = open(pipex->input_file, O_RDONLY);
			ft_check_fd(pipex->commands[i].in_fd, "Open Input File Error !\n");
			if (pipex->num_commands > 1)
				pipex->commands[i].out_fd = pipex->pipefd[1];
		}
		else if (i == pipex->num_commands - 1)
		{
			pipex->commands[i].out_fd = open(pipex->output_file, O_WRONLY | O_CREAT | O_TRUNC,
					COPYMODE);
			ft_check_fd(pipex->commands[i].out_fd, "Open Output file Error !\n");
			pipex->commands[i].in_fd = pipex->pipefd[0];
		}
		else
		{
			pipex->commands[i].in_fd = pipex->pipefd[0];
			pipex->commands[i].out_fd = pipex->pipefd[1];
		}
		ft_child_process(&pipex->commands[i], envp);
	}
	else
	{
		if (DEBUG_MODE == true)
        	ft_printf("Forked process with PID: %d for command: %s\n",
					pid, pipex->commands[i].cmd);
		if (i < pipex->num_commands - 1)
		{
			ft_parent_process(pipex);
			if (pipex->pipefd[0] != -1)
			{
				close(pipex->pipefd[0]);
				pipex->pipefd[0] = -1;
			}
		}
	}
}

void	ft_close_pipes(t_pipex *pipex)
{
	if (DEBUG_MODE == true)
        ft_printf("Closing pipe FDs: [%d, %d]\n", pipex->pipefd[0], pipex->pipefd[1]);
	if (pipex->pipefd[0] != -1)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] != -1)
		close(pipex->pipefd[1]);
}

void	ft_wait_for_children(int num_commands)
{
	int i;

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
			ft_printf("Forking for command %d: %s\n", i + 1, pipex->commands[i].cmd);
		if (i < pipex->num_commands - 1)
		{
			if (pipe(pipex->pipefd) == -1)
			{
				perror("Pipe Error !\n");
				gc_cleanup();
				exit(EXIT_FAILURE);
			}
			ft_printf("Created pipe FDs: [%d, %d]\n", pipex->pipefd[0], pipex->pipefd[1]);
		}
		pid = fork();
		ft_check_pid(pipex, envp, pid, i);
		i++;
	}
	ft_wait_for_children(pipex->num_commands);
	ft_close_pipes(pipex);
}
*/
