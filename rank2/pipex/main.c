/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/11 15:01:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	g_log_fd;

void	ft_open_log_file(void)
{
	if (DEBUG_MODE == true)
	{
		g_log_fd = open("pipex_trace.log",
				O_WRONLY | O_CREAT | O_TRUNC, COPYMODE);
		if (g_log_fd == -1)
		{
			perror("Failed to open log file");
			exit(EXIT_FAILURE);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_open_log_file();
	ft_init_pipex(&pipex, argc, argv, envp);
	if (DEBUG_MODE == true)
	{
		ft_print_pipex(&pipex);
		ft_printf_fd(g_log_fd,
			"\n\e[31mEntering ft_fork_and_exec()...\e[0m\n\n");
	}
	ft_fork_and_exec(&pipex, envp);
	gc_cleanup();
	return (EXIT_SUCCESS);
}
