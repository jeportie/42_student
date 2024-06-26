/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:31:56 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/26 17:36:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX_COMMANDS 100

typedef struct s_gc_node
{
	void				*ptr;
	bool				is_marked;
	bool				is_array;
	int					fd;
	struct s_gc_node	*next;
}				t_gc_node;

typedef struct s_garbage_collector
{
	t_gc_node	*head;
}				t_gc;

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

typedef struct	s_command
{
	char	*cmd;
	char	**args;
	int		in_fd;
	int		out_fd;
}				t_command;

typedef struct	s_pipex
{
	char		*input_file;
	char		*output_file;
	t_command	commands[MAX_COMMANDS];
	int			pipefd[2];
	int			num_commands;
}				t_pipex;

// Function declarations
void    ft_initialize_pipex(t_pipex *pipex, int argc, char **argv);
void    ft_parse_arguments(t_pipex *pipex, int argc, char **argv);
void    ft_parse_command(t_command *command, char *cmd_str);
void    ft_setup_pipes(t_pipex *pipex);
void    ft_open_files(t_pipex *pipex);

void    ft_execute_pipex(t_pipex *pipex, char **envp);
void    ft_fork_and_execute(t_pipex *pipex, char **envp);
void    ft_child_process(t_command *command, int pipefd[2], char **envp);
void    ft_parent_process(int pipefd[2]);
void    ft_redirect_io(t_command *command);
void    ft_redirect_input(int in_fd);
void    ft_redirect_output(int out_fd);
void    ft_close_pipes(t_pipex *pipex);
void    ft_wait_for_children(int num_commands);

void    ft_cleanup_pipex(t_pipex *pipex);
void    ft_close_files(t_pipex *pipex);
void    ft_free_memory(t_pipex *pipex);
void    ft_free_commands(t_command *commands, int num_commands);

/* Garbage_collector function */
void	*gc_malloc(size_t size);
void	gc_register(void *ptr);
void	gc_nest_register(void *ptr);
void	gc_fd_register(int fd);
void	gc_cleanup(void);
void	gc_collect(void);
void	gc_mark(void *ptr);	
void	gc_mark_from_roots(void);
void	gc_sweep(void);

/* Utility functions */
void	ft_exit_failure(t_pipex *pipex, int errnum);


#endif /*PIPEX_H*/	
