/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:31:56 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/10 09:12:20 by jeportie         ###   ########.fr       */
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

typedef enum e_ErrorCode
{
	ENOCHAR = 100,
	ENOEXIT,
	ENOSTART,
	ENORECT,
	ENOWALLS,
	ENODOOR,
	ENOCOL,
	ENOEXIT2,
	ENOSTART2,
	ENOFORMAT,
	ENOPATH,
	ENOINIT,
	ENOTILE,
	ENOWIN
}			t_ErrorCode;

extern t_gc		g_garbage_collector;

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
	int			prev_pipefd[2];
	int			num_commands;
}				t_pipex;

// Function declarations
void	ft_init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
void	ft_parse_args(t_pipex *pipex, int argc, char **argv, char **envp);
void	ft_setup_pipes(t_pipex *pipex);
void	ft_open_files(t_pipex *pipex);

void	ft_fork_and_exec(t_pipex *pipex, char **envp);
void	ft_exec_pid(t_pipex *pipex, char **envp, int pid, int i);
void	ft_redirect_io(t_command *command);
void	ft_close_pipes(t_pipex *pipex);

/* Utility functions */
void	ft_check_fd(int fd, const char *error_message);
void	ft_check_pid(int pid);
void	ft_check_malloc(void *ptr, const char *error_message);
char	*ft_getenv(char **envp, const char *name);

#endif /*PIPEX_H*/	
