/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:19:04 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/07 23:59:26 by jeportie         ###   ########.fr       */
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
	ft_check_malloc(args, "Split Error !\n");
	gc_nest_register(args);
	command->cmd = ft_strdup(args[0]);
	ft_check_malloc(command->cmd, "Strdup Error !\n");
	gc_register(command->cmd);
	gc_lock(command->cmd);
	if (args)
	{
		command->args = args;
		gc_nest_lock((void **)command->args);
	}
	else
		command->args = NULL;
	command->in_fd = -1;
	command->out_fd = -1;
}

void	ft_here_doc_mode(t_pipex *pipex, int argc, char **argv)
{
	int		i;
	char	*limiter;
	int		temp_fd;
	char	*line;
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	
	limiter = argv[2];
	pipex->input_file = NULL;
	pipex->output_file = argv[argc - 1];
	pipex->num_commands = argc - 4;
	temp_fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, COPYMODE);
	gc_temp_file_register("here_doc");
	ft_check_fd(temp_fd, "Open Error ! (Temp file)\n");
	gc_fd_register(temp_fd);

	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
		ft_check_fd(bytes_read, "Read Error !\n");
		buffer[bytes_read] = '\0';
		line = ft_strdup(buffer);
		ft_check_malloc(line, "Strdup Error !\n");
		gc_register(line);
		i = ft_strlen(limiter);
		if (ft_strncmp(line, limiter, i) == 0 && line[i] == '\n')
			break;
		write(temp_fd, line, ft_strlen(line));
	}
	gc_collect();
	close(temp_fd);

	pipex->input_file = ft_strdup("here_doc");
	ft_check_malloc(pipex->input_file, "Strdup Error !\n");
	gc_register(pipex->input_file);
	gc_lock(pipex->input_file);
	i = 0;
	while (i < pipex->num_commands)
	{
		ft_parse_cmd(&pipex->commands[i], argv[i + 3]);
		i++;
	}
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
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
	{
		ft_here_doc_mode(pipex, argc, argv);
		return ;
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
