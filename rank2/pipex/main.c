/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/10 09:12:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_print_command(t_command *command)
{
	int	i;

	ft_printf("Command: %s\n", command->cmd);
	if (command->args)
	{
		ft_printf("Arguments: ");
		i = 1;
		while (command->args[i])
		{
			ft_printf("%s ", command->args[i]);
			i++;
		}
		ft_printf("\n");
	}
	else
	{
		ft_printf("Arguments: None\n");
	}
	ft_printf("Input FD: %d\n", command->in_fd);
	ft_printf("Output FD: %d\n\n", command->out_fd);
}

void	ft_print_pipex(t_pipex *pipex)
{
	int	i;

	ft_printf("\nEntering ft_init_pipex()...\n\n");
	ft_printf("Input File: %s\n", pipex->input_file);
	ft_printf("Output File: %s\n", pipex->output_file);
	ft_printf("Number of Commands: %d\n\n", pipex->num_commands);
	i = 0;
	while (i < pipex->num_commands)
	{
		ft_printf("Command %d:\n", i + 1);
		ft_print_command(&pipex->commands[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_init_pipex(&pipex, argc, argv, envp);
	if (DEBUG_MODE == true)
		ft_print_pipex(&pipex);
	if (DEBUG_MODE == true)
		ft_printf("\nEntering ft_fork_and_exec()...\n\n");
	ft_fork_and_exec(&pipex, envp);
	gc_cleanup();
	return (EXIT_SUCCESS);
}
