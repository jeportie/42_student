/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:07:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/10 14:46:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_in_heredoc(int temp_fd, char *limiter)
{
	int		len;
	int		bytes_read;
	char	buffer[2048];
	char	*line;

	len = ft_strlen(limiter);
	while (1)
	{
		ft_printf("heredoc> ");
		bytes_read = read(STDIN_FILENO, buffer, 2047);
		ft_check_fd(bytes_read, "Read Error !\n");
		buffer[bytes_read] = '\0';
		line = ft_strdup(buffer);
		ft_check_malloc(line, "Strdup Error !\n");
		gc_register(line);
		if (!ft_strncmp(line, limiter, len) && line[len] == '\n')
			break ;
		write(temp_fd, line, ft_strlen(line));
	}
}

void	ft_here_doc_mode(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int		i;
	char	*limiter;
	int		temp_fd;

	limiter = argv[2];
	pipex->input_file = NULL;
	pipex->output_file = argv[argc - 1];
	pipex->num_commands = argc - 4;
	temp_fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, COPYMODE);
	ft_check_fd(temp_fd, "Open Error ! (Temp file)\n");
	gc_temp_file_register("here_doc");
	gc_fd_register(temp_fd);
	ft_in_heredoc(temp_fd, limiter);
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
