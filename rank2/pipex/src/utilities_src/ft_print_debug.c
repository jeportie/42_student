/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:00:33 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/10 16:03:45 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

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
