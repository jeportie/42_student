/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:19:04 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/10 10:21:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	gc_nest_lock(void *ptr)
{
	int		i;
	void	**array;

	if (!ptr)
		return ;
	array = (void **)ptr;
	i = 0;
	while (array[i])
	{
		gc_lock(array[i]);
		i++;
	}
}

static char	*ft_find_cmd_path(char **envp, const char *cmd)
{
	char	**paths;
	char	*path_env;
	char	*cmd_path;
	int		i;

	path_env = ft_getenv(envp, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	gc_nest_register(paths);
	gc_nest_lock(paths);
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], "/");
		ft_check_malloc(cmd_path, "Strjoin Error !\n");
		cmd_path = ft_strjoin_free(cmd_path, cmd);
		ft_check_malloc(cmd_path, "Strjoin Error !\n");
		if (access(cmd_path, X_OK) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	return (NULL);
}

static void	ft_parse_cmd(t_command *command, char *cmd_str, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd_str, ' ');
	ft_check_malloc(args, "Split Error !\n");
	gc_nest_register(args);
	cmd_path = NULL;
	if (args[0][0] != '/')
	{
		cmd_path = ft_find_cmd_path(envp, args[0]);
	}
	if (cmd_path)
	{
		command->cmd = cmd_path;
		gc_register(command->cmd);
		gc_lock(command->cmd);
	}
	else
	{
		command->cmd = ft_strdup(args[0]);
		ft_check_malloc(command->cmd, "Strdup Error !\n");
		gc_register(command->cmd);
		gc_lock(command->cmd);
	}
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

void	ft_here_doc_mode(t_pipex *pipex, int argc, char **argv, char **envp)
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
	close(temp_fd);

	pipex->input_file = ft_strdup("here_doc");
	ft_check_malloc(pipex->input_file, "Strdup Error !\n");
	gc_register(pipex->input_file);
	gc_lock(pipex->input_file);
	i = 0;
	while (i < pipex->num_commands)
	{
		ft_parse_cmd(&pipex->commands[i], argv[i + 3], envp);
		i++;
	}
}

void	ft_parse_args(t_pipex *pipex, int argc, char **argv, char **envp)
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
}
