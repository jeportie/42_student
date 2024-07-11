/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:00:33 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/11 13:36:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_print_command(t_command *command)
{
	int	i;

	ft_printf_fd(g_log_fd, "Command: %s\n", command->cmd);
	if (command->args)
	{
		ft_printf_fd(g_log_fd, "Arguments: ");
		i = 1;
		while (command->args[i])
		{
			ft_printf_fd(g_log_fd, "%s ", command->args[i]);
			i++;
		}
		ft_printf_fd(g_log_fd, "\n");
	}
	else
	{
		ft_printf_fd(g_log_fd, "Arguments: None\n");
	}
	ft_printf_fd(g_log_fd, "Input FD: %d\n", command->in_fd);
	ft_printf_fd(g_log_fd, "Output FD: %d\n\n", command->out_fd);
}

void	ft_print_pipex(t_pipex *pipex)
{
	int	i;

	ft_printf_fd(g_log_fd, "\n\e[31mEntering ft_init_pipex()...\e[0m\n\n");
	ft_printf_fd(g_log_fd, "Input File: %s\n", pipex->input_file);
	ft_printf_fd(g_log_fd, "Output File: %s\n", pipex->output_file);
	ft_printf_fd(g_log_fd, "Number of Commands: %d\n\n", pipex->num_commands);
	i = 0;
	while (i < pipex->num_commands)
	{
		ft_printf_fd(g_log_fd, "Command %d:\n", i + 1);
		ft_print_command(&pipex->commands[i]);
		i++;
	}
}
