/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/10 16:02:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_init_pipex(&pipex, argc, argv, envp);
	if (DEBUG_MODE == true)
	{
		ft_print_pipex(&pipex);
		ft_printf("\nEntering ft_fork_and_exec()...\n\n");
	}
	ft_fork_and_exec(&pipex, envp);
	gc_cleanup();
	return (EXIT_SUCCESS);
}
