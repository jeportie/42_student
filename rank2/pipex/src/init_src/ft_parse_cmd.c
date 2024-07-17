/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:11:48 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/11 08:36:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_check_cmd_path(t_command *command, char *cmd_path, char **args,
	char **envp)
{
	if (args[0][0] != '/')
	{
		cmd_path = ft_find_cmd_path(envp, args[0]);
		if (!cmd_path)
		{
			perror("Error ! Command do not exist.\n");
			gc_cleanup();
			exit(EXIT_FAILURE);
		}
		command->cmd = cmd_path;
		gc_register(command->cmd);
		gc_lock(command->cmd);
	}
	else
		command->cmd = args[0];
}

void	ft_parse_cmd(t_command *command, char *cmd_str, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd_str, ' ');
	ft_check_malloc(args, "Split Error !\n");
	gc_nest_register(args);
	gc_nest_lock(args);
	cmd_path = NULL;
	ft_check_cmd_path(command, cmd_path, args, envp);
	if (args)
		command->args = args;
	else
		command->args = NULL;
	command->in_fd = -1;
	command->out_fd = -1;
}
