/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:19:04 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/06 15:31:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	gc_nest_lock(void **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		gc_lock(ptr[i]);
		i++;
	}
}

static void	ft_parse_cmd(t_command *command, char *cmd_str)
{
	char	**args;

	args = ft_split(cmd_str, ' ');
	if (!args)
	{
		perror("Split Error !\n");
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
	gc_nest_register(args);
	command->cmd = ft_strdup(args[0]);
	if (!command->cmd)
	{
		perror("Strdup Error !\n");
		gc_cleanup();
		exit (EXIT_FAILURE);
	}
	gc_register(command->cmd);
	gc_lock(command->cmd);
	if (args[1])
	{
		command->args = &args[1];
		gc_nest_lock((void **)command->args);
	}
	else
		command->args = NULL;
}

void	ft_parse_args(t_pipex *pipex, int argc, char **argv)
{
	int	i;

	if (argc < 5)
	{
		ft_putstr_fd("Usage : ./pipex <file1><cmd1><cmd2>...file2\n",
			STDERR_FILENO);
		gc_cleanup();
		exit (EXIT_FAILURE);
	}
	pipex->input_file = argv[1];
	pipex->output_file = argv[argc - 1];
	pipex->num_commands = argc - 3;
	i = 0;
	while (i < pipex->num_commands)
	{
		ft_parse_cmd(&pipex->commands[i], argv[i + 2]);
		i++;
	}
}
