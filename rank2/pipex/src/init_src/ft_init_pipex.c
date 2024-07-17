/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:21:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/16 11:22:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int	i;

	if (argc < 5)
	{
		ft_putstr_fd("Usage : ./pipex <file1><cmd1><cmd2>...file2\n",
			STDERR_FILENO);
		gc_cleanup();
		exit (EXIT_FAILURE);
	}
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
	{
		ft_here_doc_mode(pipex, argc, argv, envp);
		return ;
	}
	pipex->input_file = argv[1];
	pipex->output_file = argv[argc - 1];
	pipex->num_commands = argc - 3;
	i = 0;
	while (i < pipex->num_commands)
	{
		ft_parse_cmd(&pipex->commands[i], argv[i + 2], envp);
		i++;
	}
	gc_collect();
}
