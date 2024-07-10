/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:11:48 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/10 11:56:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_parse_cmd(t_command *command, char *cmd_str, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd_str, ' ');
	ft_check_malloc(args, "Split Error !\n");
	gc_nest_register(args);
	gc_nest_lock(args);
	cmd_path = NULL;
	if (args[0][0] != '/')
		cmd_path = ft_find_cmd_path(envp, args[0]);
	if (cmd_path)
	{
		command->cmd = cmd_path;
		gc_register(command->cmd);
		gc_lock(command->cmd);
	}
	else
		command->cmd = args[0];
	if (args)
		command->args = args;
	else
		command->args = NULL;
	command->in_fd = -1;
	command->out_fd = -1;
}
