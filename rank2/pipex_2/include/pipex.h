/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:31:56 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/15 09:36:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include <fcntl.h>

# define MAX_COMMANDS 100
# define COPYMODE 0644
# define DEBUG_MODE 1
# define ERROR -1
# define CHILD 0

typedef struct s_command
{
	char	*cmd;
	char	**args;
	int		in_fd;
	int		out_fd;
}				t_command;

typedef struct s_pipex
{
	char		*input_file;
	char		*output_file;
	t_command	commands[MAX_COMMANDS];
	int			pipefd[2];
	int			num_commands;
}				t_pipex;

extern int	g_log_fd;

//  Pipex Init Functions
void	ft_init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
void	ft_parse_args(t_pipex *pipex, int argc, char **argv, char **envp);
void	ft_parse_cmd(t_command *command, char *cmd_str, char **envp);
void	ft_open_files(t_pipex *pipex);
void	ft_here_doc_mode(t_pipex *pipex, int argc, char **argv, char **envp);

//	Pipex Process Functions
void	ft_fork_and_exec(t_pipex *pipex, char **envp);
void	ft_exec_pid(t_pipex *pipex, char **envp, int pid, int i);
void	ft_redirect_input(int in_fd);
void	ft_redirect_output(int out_fd);

/* Utility functions */
void	ft_print_command(t_command *command);
void	ft_print_pipex(t_pipex *pipex);

#endif /*PIPEX_H*/	
